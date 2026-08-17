/*
 * DoorService.cpp
 *
 * Created: 2026-08-17 6:05:31 AM
 *  Author: admin
 */ 

#include "DoorService/DoorService.h"

namespace DoorService
{
    /*
     * Constructor
     *
     * A newly created DoorService begins in the Closed state.
     *
     * This establishes the initial state of the HSM.
     */
    DoorService::DoorService()
        : currentState(DoorState::Closed)
    {
    }


    /*
     * ProcessEvent()
     *
     * This is the heart of our first HSM.
     *
     * Every event enters here.
     *
     * The current state determines which events are meaningful
     * and what action should be taken when one arrives.
     */
    void DoorService::ProcessEvent(DoorEvent event)
    {
        /*
         * The switch operates on the HSM's CURRENT state.
         *
         * Each case therefore represents one state in our Mermaid
         * state diagram.
         */
        switch (currentState)
        {
            case DoorState::Closed:

                /*
                 * Mermaid:
                 *
                 *     Closed --> Opening : OpenRequest
                 *
                 * An OpenRequest is meaningful while the door
                 * is Closed.
                 */
                if (event == DoorEvent::OpenRequest)
                {
                    currentState = DoorState::Opening;
                }

                break;


            case DoorState::Opening:

                /*
                 * Mermaid:
                 *
                 *     Opening --> Open : OpenPositionReached
                 *
                 * Once the simulated door has reached its open
                 * position, the HSM changes to Open.
                 */
                if (event == DoorEvent::OpenPositionReached)
                {
                    currentState = DoorState::Open;
                }

                break;


            case DoorState::Open:

                /*
                 * Mermaid:
                 *
                 *     Open --> Closing : CloseRequest
                 */
                if (event == DoorEvent::CloseRequest)
                {
                    currentState = DoorState::Closing;
                }

                break;


            case DoorState::Closing:

                /*
                 * Mermaid:
                 *
                 *     Closing --> Closed : ClosedPositionReached
                 */
                if (event == DoorEvent::ClosedPositionReached)
                {
                    currentState = DoorState::Closed;
                }

                break;
        }
    }


    /*
     * CurrentState()
     *
     * Return the current state without allowing the caller to
     * modify it.
     *
     * The "const" at the end means that this function promises
     * not to modify the DoorService object.
     */
    DoorState DoorService::CurrentState() const
    {
        return currentState;
    }
}