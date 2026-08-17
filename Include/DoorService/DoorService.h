/*
 * DoorService.h
 *
 * Created: 2026-08-17 5:59:04 AM
 *  Author: admin
 */ 


#ifndef DOORSERVICE_H_
#define DOORSERVICE_H_

#pragma once

namespace DoorService
{
    /*
     * DoorState represents the current operational state of the
     * DoorService state machine.
     *
     * This is deliberately an enum class rather than a plain enum.
     *
     * The "class" portion gives the enumeration its own scope, so
     * we refer to the values as:
     *
     *     DoorState::Closed
     *     DoorState::Opening
     *
     * rather than simply:
     *
     *     Closed
     *     Opening
     *
     * This prevents these names from leaking into the surrounding
     * namespace and potentially colliding with names used elsewhere
     * in the elevator controller.
     */
    enum class DoorState
    {
        Closed,
        Opening,
        Open,
        Closing
    };


    /*
     * DoorEvent represents something that the DoorService HSM can
     * react to.
     *
     * An event is NOT a state.
     *
     * "Opening" means:
     *
     *     We ARE currently opening the door.
     *
     * "OpenRequest" means:
     *
     *     Something has REQUESTED that we open the door.
     */
    enum class DoorEvent
    {
        OpenRequest,
        OpenPositionReached,
        CloseRequest,
        ClosedPositionReached
    };


    /*
     * DoorService is the beginning of our DoorService HSM.
     *
     * For this first implementation, the HSM contains only enough
     * behavior to demonstrate state transitions.
     *
     * No physical door motor is commanded yet.
     *
     * No laser sensors are evaluated yet.
     *
     * No safety authority is acquired yet.
     *
     * Those will be added only after we understand the basic
     * state-transition mechanism.
     */
    class DoorService
    {
    public:

        /*
         * Construct a new DoorService HSM.
         *
         * The machine begins in the Closed state.
         */
        DoorService();


        /*
         * Process one event presented to the HSM.
         *
         * ProcessEvent() examines:
         *
         *     1. The current state.
         *     2. The incoming event.
         *
         * It then determines whether that event is meaningful in
         * the current state and, if so, performs the appropriate
         * state transition.
         */
        void ProcessEvent(DoorEvent event);


        /*
         * Return the current state of the HSM.
         *
         * This is useful for our diagnostic/test code because it
         * allows us to observe the state without directly modifying it.
         */
        DoorState CurrentState() const;


    private:

        /*
         * This variable is the HSM's current state.
         *
         * It is deliberately private.
         *
         * Code outside DoorService cannot simply do:
         *
         *     door.currentState = DoorState::Open;
         *
         * Instead, state changes occur through the HSM's transition
         * logic in ProcessEvent().
         *
         * This is one of the first practical examples of why we
         * wanted to use classes in the first place.
         */
        DoorState currentState;
    };
}




#endif /* DOORSERVICE_H_ */