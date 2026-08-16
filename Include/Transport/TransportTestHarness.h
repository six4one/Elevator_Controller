/*
 * TransportTestHarness.h
 *
 * Created: 2026-08-15 5:50:09 PM
 *  Author: admin
 *
 * Purpose:
 *     Hardware-independent exercise of the TransportSequencer and
 *     TransportPositionResolver.
 *
 * This harness does NOT command ClearCore motors.
 */

#ifndef TRANSPORTTESTHARNESS_H_
#define TRANSPORTTESTHARNESS_H_

#include "TransportTypes.h"

namespace Transport
{
    /*
     * TransportTestHarness
     *
     * Simulates successful completion of each commanded Transport position.
     *
     * This allows the choreography and physical pulse targets to be examined
     * before CommandMove has any authority to operate real motors.
     */
    class TransportTestHarness
    {
    public:

        /*
         * Run a complete simulated trip from the sequencer's current
         * position to target.
         *
         * Each successfully "completed" position is printed to the
         * diagnostic output.
         */
        void RunTo(TransportPositionId target);
    };
}

#endif /* TRANSPORTTESTHARNESS_H_ */