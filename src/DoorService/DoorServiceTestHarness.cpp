/*
 * DoorServiceTestHarness.cpp
 *
 * Hardware-independent diagnostic exercise of the DoorService HSM.
 */

#include "DoorService/DoorServiceTestHarness.h"

#include "DoorService/DoorService.h"

#include "ClearCore.h"

#include <stdio.h>

namespace DoorService
{
    static const char* StateName(DoorState state)
    {
        switch (state)
        {
            case DoorState::Closed:
                return "Closed";

            case DoorState::Opening:
                return "Opening";

            case DoorState::Open:
                return "Open";

            case DoorState::Closing:
                return "Closing";
				
			case DoorState::Halting:
			    return "Halting";

			case DoorState::Halted:
			    return "Halted";
        }

        return "UNKNOWN";
    }


    static void ReportState(DoorService& doorService)
    {
        char message[96];

        snprintf(message,
                 sizeof(message),
                 "State: %s",
                 StateName(doorService.CurrentState()));

        ConnectorUsb.SendLine(message);
    }


    void DoorServiceTestHarness::RunBasicTest()
    {
        /*
         * Print the diagnostic header BEFORE constructing the HSM.
         *
         * The constructor executes the initial Closed entry action,
         * which now includes a two-second delay.
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("========================================");
        ConnectorUsb.SendLine("DoorService HSM Entry/Exit Diagnostic");
        ConnectorUsb.SendLine("========================================");


        /*
         * Create the DoorService HSM.
         *
         * Construction enters Closed and therefore executes the
         * Closed entry action.
         */
        DoorService doorService;


        /*
         * --------------------------------------------------------
         * INITIAL STATE
         * --------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("Initial state:");

        ReportState(doorService);


        /*
         * --------------------------------------------------------
         * TEST 1
         *
         * Invalid event while Closed.
         *
         * No transition should occur.
         *
         * Therefore there should be:
         *
         *     NO EXIT: Closed
         *     NO ENTER: ...
         *
         * --------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 1: Invalid event in Closed");
        ConnectorUsb.SendLine("Event: CloseRequest");

        doorService.ProcessEvent(DoorEvent::CloseRequest);

        ReportState(doorService);


        /*
         * --------------------------------------------------------
         * TEST 2
         *
         * Closed --> Opening
         *
         * Expected sequence:
         *
         *     EXIT: Closed
         *     ENTER: Opening
         *     2 second delay
         * --------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 2: Closed -> Opening");
        ConnectorUsb.SendLine("Event: OpenRequest");

        doorService.ProcessEvent(DoorEvent::OpenRequest);

        ReportState(doorService);


        /*
         * --------------------------------------------------------
         * TEST 3
         *
         * Invalid event while Opening.
         *
         * No transition should occur.
         * --------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 3: Invalid event in Opening");
        ConnectorUsb.SendLine("Event: OpenRequest");

        doorService.ProcessEvent(DoorEvent::OpenRequest);

        ReportState(doorService);


        /*
         * --------------------------------------------------------
         * TEST 4
         *
         * Opening --> Open
         *
         * Expected sequence:
         *
         *     EXIT: Opening
         *     ENTER: Open
         *     2 second delay
         * --------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 4: Opening -> Open");
        ConnectorUsb.SendLine("Event: OpenPositionReached");

        doorService.ProcessEvent(DoorEvent::OpenPositionReached);

        ReportState(doorService);


        /*
         * --------------------------------------------------------
         * TEST 5
         *
         * Open --> Closing
         *
         * Expected sequence:
         *
         *     EXIT: Open
         *     ENTER: Closing
         *     2 second delay
         * --------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 5: Open -> Closing");
        ConnectorUsb.SendLine("Event: CloseRequest");

        doorService.ProcessEvent(DoorEvent::CloseRequest);

        ReportState(doorService);


        /*
         * --------------------------------------------------------
         * TEST 6
         *
         * Closing --> Closed
         *
         * Expected sequence:
         *
         *     EXIT: Closing
         *     ENTER: Closed
         *     2 second delay
         * --------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 6: Closing -> Closed");
        ConnectorUsb.SendLine("Event: ClosedPositionReached");

        doorService.ProcessEvent(DoorEvent::ClosedPositionReached);

        ReportState(doorService);


        /*
         * --------------------------------------------------------
         * TEST COMPLETE
         * --------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("DoorService entry/exit test returned.");
    }
}