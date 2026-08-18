/*
 * DoorService.h
 *
 * Beginning of the DoorService HSM implementation.
 *
 * Current implementation:
 *     Educational / diagnostic state machine.
 *
 * No physical door hardware is commanded yet.
 */

#ifndef DOORSERVICE_H_
#define DOORSERVICE_H_

namespace DoorService
{
    /*
     * ------------------------------------------------------------
     * DOOR STATES
     * ------------------------------------------------------------
     */
    enum class DoorState
    {
        Closed,
        Opening,
        Open,
        Closing,

        /*
         * Transitional state used while commanding the door motor
         * to stop following an obstruction.
         */
        Halting,

        /*
         * Verified stopped condition following a halt.
         *
         * This is not intended to be a normal resting state.
         * A subsequent OpenRequest or CloseRequest will establish
         * the next desired canonical door position.
         */
        Halted
    };


    /*
     * ------------------------------------------------------------
     * DOOR EVENTS
     * ------------------------------------------------------------
     */
    enum class DoorEvent
    {
        OpenRequest,
        OpenPositionReached,
        CloseRequest,
        ClosedPositionReached,

        /*
         * Obstruction detected while door motion is active.
         */
        ObstructionDetected,

        /*
         * Motor has been verified to have stopped following
         * a halt command.
         */
        MotionStopped
    };


    /*
     * ------------------------------------------------------------
     * DOORSERVICE HSM
     * ------------------------------------------------------------
     */
    class DoorService
    {
    public:

        DoorService();

        /*
         * Present an event to the HSM.
         */
        void ProcessEvent(DoorEvent event);

        /*
         * Return the current state.
         */
        DoorState CurrentState() const;


    private:

        DoorState currentState;


        /*
         * Enter a new state.
         *
         * This performs:
         *
         *     1. Exit action for the current state.
         *     2. State change.
         *     3. Entry action for the new state.
         */
        void EnterState(DoorState newState);


        /*
         * State entry actions.
         */
        void OnEnterClosed();
        void OnEnterOpening();
        void OnEnterOpen();
        void OnEnterClosing();
        void OnEnterHalting();
        void OnEnterHalted();


        /*
         * State exit actions.
         */
        void OnExitClosed();
        void OnExitOpening();
        void OnExitOpen();
        void OnExitClosing();
        void OnExitHalting();
        void OnExitHalted();
    };
}

#endif /* DOORSERVICE_H_ */