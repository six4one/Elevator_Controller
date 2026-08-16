/*
 * TransportTestHarness.cpp
 *
 * Created: 2026-08-15 5:51:08 PM
 *  Author: admin
 *
 * Purpose:
 *     Hardware-independent diagnostic exercise of the Transport layer.
 */

#include "Transport/TransportTestHarness.h"

#include "Transport/TransportPositionResolver.h"
#include "Transport/TransportPositions.h"
#include "Transport/TransportSequencer.h"

#include "Elevator_Params.h"

#include "ClearCore.h"
#include <stdio.h>

namespace Transport
{
    /*
     * Convert cab pulses back into inches.
     *
     * This conversion exists ONLY for human-readable diagnostic output.
     * The canonical pulse values remain authoritative for motor commands.
     */
    static float CabPulsesToInches(uint32_t pulses)
    {
        return (float)pulses / cabCountsPerInch;
    }

    /*
     * Convert door pulses back into inches.
     *
     * Again, this is diagnostic only.
     */
    static float DoorPulsesToInches(uint32_t pulses)
    {
        return (float)pulses / doorCountsPerInch;
    }

    /*
     * Return a human-readable name for a TransportPositionId.
     *
     * This is deliberately kept in the test harness. We do not want
     * diagnostic naming code contaminating the Transport decision logic.
     */
    static const char* PositionName(TransportPositionId position)
    {
        switch (position)
        {
            case TransportPositionId::Basement:
                return "Basement";

            case TransportPositionId::BasementDocked:
                return "BasementDocked";

            case TransportPositionId::BasementStaging:
                return "BasementStaging";

            case TransportPositionId::Garage:
                return "Garage";

            case TransportPositionId::GarageDocked:
                return "GarageDocked";

            case TransportPositionId::GarageStaging:
                return "GarageStaging";

            case TransportPositionId::Main:
                return "Main";

            case TransportPositionId::Apartment:
                return "Apartment";
        }

        return "UNKNOWN";
    }

    /*
     * RunTo()
     *
     * The test harness creates its own TransportSequencer and
     * TransportPositionResolver objects.
     *
     * Each call to Next() asks:
     *
     *     "What stable position should be commanded next?"
     *
     * The harness then resolves that position into motor pulses and
     * pretends that the move succeeded.
     *
     * Only after that simulated success does it call CommitPosition().
     */
    void TransportTestHarness::RunTo(TransportPositionId target)
    {
        TransportSequencer sequencer;
        TransportPositionResolver resolver;

        ConnectorUsb.SendLine("");
        ConnectorUsb.SendLine("========================================");
        char message[96];

        snprintf(message,
                 sizeof(message),
                 "Transport test: %s -> %s",
                 PositionName(sequencer.CurrentPosition()),
                 PositionName(target));

        ConnectorUsb.SendLine(message);
        ConnectorUsb.SendLine("========================================");

        /*
         * Continue until the sequencer reports that its current position
         * equals the requested target.
         */
        while (sequencer.CurrentPosition() != target)
        {
            /*
             * Ask the sequencer for the next stable Transport position.
             */
            const TransportPositionId next =
                sequencer.Next(target);

            /*
             * Translate the semantic position into absolute pulse targets.
             */
            TransportMotorPositions motorPositions;

            if (!resolver.Resolve(next, motorPositions))
            {
                /*
                 * A failed resolution means the semantic table and the
                 * physical parameter mapping disagree.
                 *
                 * In a real system this would be a serious configuration
                 * fault. The test therefore stops immediately.
                 */

                snprintf(message,
                         sizeof(message),
                         "ERROR: Unable to resolve %s",
                         PositionName(next));

                ConnectorUsb.SendLine(message);
                return;
            }

            ConnectorUsb.SendLine("");

            snprintf(message,
                     sizeof(message),
                     "NEXT: %s",
                     PositionName(next));

            ConnectorUsb.SendLine(message);

            snprintf(message,
                     sizeof(message),
                     "  Cab:   %lu pulses  (%.4f in)",
                     (unsigned long)motorPositions.cab,
                     CabPulsesToInches(motorPositions.cab));

            ConnectorUsb.SendLine(message);

            snprintf(message,
                     sizeof(message),
                     "  DoorX: %lu pulses  (%.4f in)",
                     (unsigned long)motorPositions.doorX,
                     DoorPulsesToInches(motorPositions.doorX));

            ConnectorUsb.SendLine(message);

            snprintf(message,
                     sizeof(message),
                     "  DoorY: %lu pulses  (%.4f in)",
                     (unsigned long)motorPositions.doorY,
                     DoorPulsesToInches(motorPositions.doorY));

            ConnectorUsb.SendLine(message);

            /*
             * HARDWARE IS NOT BEING MOVED HERE.
             *
             * This is the simulated success boundary.
             *
             * Later, CommandMove will replace this conceptual step.
             * It will command the required motors and return only after
             * the move has actually satisfied its completion criteria.
             */
            sequencer.CommitPosition(next);

            ConnectorUsb.SendLine("  Result: simulated move successful");
        }

        ConnectorUsb.SendLine("");

        snprintf(message,
                 sizeof(message),
                 "ARRIVED: %s",
                 PositionName(sequencer.CurrentPosition()));

        ConnectorUsb.SendLine(message);
    }
}
