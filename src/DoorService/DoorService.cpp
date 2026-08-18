/*
 * DoorService.cpp
 *
 * Beginning of the DoorService HSM implementation.
 *
 * No physical door hardware is commanded yet.
 */

#include "DoorService/DoorService.h"

#include "ClearCore.h"

namespace DoorService
{
    /*
     * ------------------------------------------------------------
     * CONSTRUCTOR
     * ------------------------------------------------------------
     */
    DoorService::DoorService()
        : currentState(DoorState::Closed)
    {
        OnEnterClosed();
    }


    /*
     * ------------------------------------------------------------
     * CURRENT STATE
     * ------------------------------------------------------------
     */
    DoorState DoorService::CurrentState() const
    {
        return currentState;
    }


    /*
     * ------------------------------------------------------------
     * PROCESS EVENT
     * ------------------------------------------------------------
     *
     * The event is interpreted according to the current state.
     *
     * If no transition exists for the event in the current state,
     * nothing happens.
     */
    void DoorService::ProcessEvent(DoorEvent event)
    {
        switch (currentState)
        {
            /*
             * ----------------------------------------------------
             * CLOSED
             * ----------------------------------------------------
             */
            case DoorState::Closed:

                if (event == DoorEvent::OpenRequest)
                {
                    EnterState(DoorState::Opening);
                }

                break;


            /*
             * ----------------------------------------------------
             * OPENING
             * ----------------------------------------------------
             */
            case DoorState::Opening:

                if (event == DoorEvent::OpenPositionReached)
                {
                    EnterState(DoorState::Open);
                }
                else if (event == DoorEvent::ObstructionDetected)
                {
                    EnterState(DoorState::Halting);
                }

                break;


            /*
             * ----------------------------------------------------
             * OPEN
             * ----------------------------------------------------
             */
            case DoorState::Open:

                if (event == DoorEvent::CloseRequest)
                {
                    EnterState(DoorState::Closing);
                }

                break;


            /*
             * ----------------------------------------------------
             * CLOSING
             * ----------------------------------------------------
             */
            case DoorState::Closing:

                if (event == DoorEvent::ClosedPositionReached)
                {
                    EnterState(DoorState::Closed);
                }
                else if (event == DoorEvent::ObstructionDetected)
                {
                    EnterState(DoorState::Halting);
                }

                break;


            /*
             * ----------------------------------------------------
             * HALTING
             * ----------------------------------------------------
             *
             * The motor has been commanded to stop.
             *
             * For this educational implementation, MotionStopped
             * is supplied by the test harness.
             */
            case DoorState::Halting:

                if (event == DoorEvent::MotionStopped)
                {
                    EnterState(DoorState::Halted);
                }

                break;


            /*
             * ----------------------------------------------------
             * HALTED
             * ----------------------------------------------------
             *
             * The previous motion has been terminated and the
             * stopped condition has been verified.
             *
             * A subsequent OpenRequest or CloseRequest establishes
             * the next desired canonical door position.
             */
            case DoorState::Halted:

                if (event == DoorEvent::OpenRequest)
                {
                    EnterState(DoorState::Opening);
                }
                else if (event == DoorEvent::CloseRequest)
                {
                    EnterState(DoorState::Closing);
                }

                break;
        }
    }


    /*
     * ------------------------------------------------------------
     * ENTER STATE
     * ------------------------------------------------------------
     *
     * Sequence:
     *
     *     EXIT current state
     *             ?
     *     change currentState
     *             ?
     *     ENTER new state
     */
    void DoorService::EnterState(DoorState newState)
    {
        /*
         * Exit current state.
         */
        switch (currentState)
        {
            case DoorState::Closed:
                OnExitClosed();
                break;

            case DoorState::Opening:
                OnExitOpening();
                break;

            case DoorState::Open:
                OnExitOpen();
                break;

            case DoorState::Closing:
                OnExitClosing();
                break;

            case DoorState::Halting:
                OnExitHalting();
                break;

            case DoorState::Halted:
                OnExitHalted();
                break;
        }


        /*
         * Change state.
         */
        currentState = newState;


        /*
         * Enter new state.
         */
        switch (currentState)
        {
            case DoorState::Closed:
                OnEnterClosed();
                break;

            case DoorState::Opening:
                OnEnterOpening();
                break;

            case DoorState::Open:
                OnEnterOpen();
                break;

            case DoorState::Closing:
                OnEnterClosing();
                break;

            case DoorState::Halting:
                OnEnterHalting();
                break;

            case DoorState::Halted:
                OnEnterHalted();
                break;
        }
    }


    /*
     * ============================================================
     * STATE ENTRY ACTIONS
     * ============================================================
     *
     * The two-second delays remain for this educational test.
     * They will eventually be removed when real non-blocking
     * state behavior is introduced.
     */


    void DoorService::OnEnterClosed()
    {
        ConnectorUsb.SendLine("ENTER: Closed");
        ConnectorUsb.SendLine("Action: Door is considered closed.");

        Delay_ms(2000);
    }


    void DoorService::OnEnterOpening()
    {
        ConnectorUsb.SendLine("ENTER: Opening");
        ConnectorUsb.SendLine(
            "Action: Door opening sequence would begin here.");

        Delay_ms(2000);
    }


    void DoorService::OnEnterOpen()
    {
        ConnectorUsb.SendLine("ENTER: Open");
        ConnectorUsb.SendLine("Action: Door is considered fully open.");

        Delay_ms(2000);
    }


    void DoorService::OnEnterClosing()
    {
        ConnectorUsb.SendLine("ENTER: Closing");
        ConnectorUsb.SendLine(
            "Action: Door closing sequence would begin here.");

        Delay_ms(2000);
    }


    void DoorService::OnEnterHalting()
    {
        ConnectorUsb.SendLine("ENTER: Halting");
        ConnectorUsb.SendLine(
            "Action: Door motor would be commanded to stop.");

        Delay_ms(2000);
    }


    void DoorService::OnEnterHalted()
    {
        ConnectorUsb.SendLine("ENTER: Halted");
        ConnectorUsb.SendLine(
            "Action: Door motion is considered stopped.");

        Delay_ms(2000);
    }


    /*
     * ============================================================
     * STATE EXIT ACTIONS
     * ============================================================
     */


    void DoorService::OnExitClosed()
    {
        ConnectorUsb.SendLine("EXIT: Closed");
    }


    void DoorService::OnExitOpening()
    {
        ConnectorUsb.SendLine("EXIT: Opening");
    }


    void DoorService::OnExitOpen()
    {
        ConnectorUsb.SendLine("EXIT: Open");
    }


    void DoorService::OnExitClosing()
    {
        ConnectorUsb.SendLine("EXIT: Closing");
    }


    void DoorService::OnExitHalting()
    {
        ConnectorUsb.SendLine("EXIT: Halting");
    }


    void DoorService::OnExitHalted()
    {
        ConnectorUsb.SendLine("EXIT: Halted");
    }
}