/*
 * DoorServiceTestHarness.cpp
 *
 * Purpose:
 *     Hardware-independent diagnostic exercise of the DoorService HSM.
 *
 * This harness does NOT command door motors.
 */

#include "DoorService/DoorServiceTestHarness.h"

#include "ClearCore.h"

#include <stdio.h>

namespace DoorService
{
    /*
     * Convert a DoorState enumeration value into a human-readable
     * string for diagnostic output.
     */
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
        }

        return "UNKNOWN";
    }


    /*
     * Report the current HSM state.
     */
    static void ReportState(DoorService& doorService)
    {
        char message[96];

        snprintf(message,
                 sizeof(message),
                 "State: %s",
                 StateName(doorService.CurrentState()));

        ConnectorUsb.SendLine(message);
    }


    /*
     * RunBasicTest()
     *
     * Exercise the DoorService HSM, including events which are
     * deliberately invalid for the current state.
     *
     * Expected state sequence:
     *
     *     Closed
     *         + CloseRequest
     *         -> Closed
     *
     *     Closed
     *         + OpenRequest
     *         -> Opening
     *
     *     Opening
     *         + OpenRequest
     *         -> Opening
     *
     *     Opening
     *         + OpenPositionReached
     *         -> Open
     *
     *     Open
     *         + CloseRequest
     *         -> Closing
     *
     *     Closing
     *         + ClosedPositionReached
     *         -> Closed
     */
    void DoorServiceTestHarness::RunBasicTest()
    {
        /*
         * Create the DoorService HSM.
         *
         * Construction should place it in Closed.
         */
        DoorService doorService;


        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("========================================");
        ConnectorUsb.SendLine("DoorService HSM Diagnostic");
        ConnectorUsb.SendLine("========================================");


        /*
         * ------------------------------------------------------------
         * INITIAL STATE
         * ------------------------------------------------------------
         */
        ConnectorUsb.SendLine("Initial state:");

        ReportState(doorService);


        /*
         * ------------------------------------------------------------
         * TEST 1 — INVALID EVENT
         *
         * Closed + CloseRequest
         *
         * There is no transition:
         *
         *     Closed --> Closing : CloseRequest
         *
         * Therefore the state must remain Closed.
         * ------------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 1: Invalid event in Closed");
        ConnectorUsb.SendLine("Event: CloseRequest");

        doorService.ProcessEvent(DoorEvent::CloseRequest);

        ReportState(doorService);


        /*
         * ------------------------------------------------------------
         * TEST 2 — VALID TRANSITION
         *
         * Closed --> Opening : OpenRequest
         * ------------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 2: Valid transition");
        ConnectorUsb.SendLine("Event: OpenRequest");

        doorService.ProcessEvent(DoorEvent::OpenRequest);

        ReportState(doorService);


        /*
         * ------------------------------------------------------------
         * TEST 3 — INVALID EVENT
         *
         * Opening + OpenRequest
         *
         * There is no transition:
         *
         *     Opening --> ??? : OpenRequest
         *
         * Therefore the state must remain Opening.
         * ------------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 3: Invalid event in Opening");
        ConnectorUsb.SendLine("Event: OpenRequest");

        doorService.ProcessEvent(DoorEvent::OpenRequest);

        ReportState(doorService);


        /*
         * ------------------------------------------------------------
         * TEST 4 — VALID TRANSITION
         *
         * Opening --> Open : OpenPositionReached
         * ------------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 4: Valid transition");
        ConnectorUsb.SendLine("Event: OpenPositionReached");

        doorService.ProcessEvent(DoorEvent::OpenPositionReached);

        ReportState(doorService);


        /*
         * ------------------------------------------------------------
         * TEST 5 — VALID TRANSITION
         *
         * Open --> Closing : CloseRequest
         * ------------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 5: Valid transition");
        ConnectorUsb.SendLine("Event: CloseRequest");

        doorService.ProcessEvent(DoorEvent::CloseRequest);

        ReportState(doorService);


        /*
         * ------------------------------------------------------------
         * TEST 6 — VALID TRANSITION
         *
         * Closing --> Closed : ClosedPositionReached
         * ------------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("TEST 6: Valid transition");
        ConnectorUsb.SendLine("Event: ClosedPositionReached");

        doorService.ProcessEvent(DoorEvent::ClosedPositionReached);

        ReportState(doorService);


        /*
         * ------------------------------------------------------------
         * TEST COMPLETE
         * ------------------------------------------------------------
         */
        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("DoorService HSM test returned.");
    }
}