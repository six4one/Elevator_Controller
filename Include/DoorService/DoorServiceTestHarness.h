/*
 * DoorServiceTestHarness.h
 *
 * Created: 2026-08-17 7:56:08 AM
 *  Author: admin
 *
 * DoorServiceTestHarness.h
 *
 * Purpose:
 *     Hardware-independent diagnostic exercise of the DoorService HSM.
 *
 * This harness does NOT command a door motor.
 *
 * Its purpose at this stage is to demonstrate and verify the mechanics
 * of state transitions in the DoorService HSM.
 */

#ifndef DOORSERVICETESTHARNESS_H_
#define DOORSERVICETESTHARNESS_H_

#include "DoorService/DoorService.h"

namespace DoorService
{
    /*
     * DoorServiceTestHarness
     *
     * Drives the DoorService HSM through a deliberately simple sequence
     * of events and reports the resulting states over the ClearCore
     * USB serial connection.
     *
     * This is analogous to the TransportTestHarness we developed earlier.
     */
    class DoorServiceTestHarness
    {
    public:

        /*
         * Run the basic DoorService state-transition demonstration.
         *
         * The expected sequence is:
         *
         *     Closed
         *        ? OpenRequest
         *     Opening
         *        ? OpenPositionReached
         *     Open
         *        ? CloseRequest
         *     Closing
         *        ? ClosedPositionReached
         *     Closed
         *
         * No physical hardware is commanded.
         */
        void RunBasicTest();
    };
}

#endif /* DOORSERVICETESTHARNESS_H_ */