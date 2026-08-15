/*
 * TransportSequencer.h
 *
 * Created: 2026-08-15 4:45:29 PM
 *  Author: admin
 */ 


#ifndef TRANSPORTSEQUENCER_H_
#define TRANSPORTSEQUENCER_H_

#include "TransportTypes.h"

namespace Transport
{
    /*
     * TransportSequencer owns the logical progress of a Transport move.
     *
     * currentPosition represents the last canonical position that the
     * Transport system has successfully achieved. It is deliberately kept
     * inside this class rather than represented as a global variable.
     *
     * The sequencer does not command motors. Its responsibility is to
     * determine which canonical position should be commanded next.
     */
    class TransportSequencer
    {
    public:

        /*
         * Constructor.
         *
         * A newly-created sequencer begins at the Basement position.
         * This is the first valid Transport position in the canonical table.
         */
        TransportSequencer();

        /*
         * Determine the next canonical position required to reach target.
         *
         * The current position is retained internally by the sequencer,
         * therefore the caller only supplies the requested destination.
         *
         * The returned position is the next stable position that should be
         * presented to CommandMove.
         */
        TransportPositionId Next(TransportPositionId target);

        /*
         * Record that a commanded position has been successfully achieved.
         *
         * Asking for a move does not mean that the move succeeded.
         * currentPosition changes only after the motion-control layer
         * confirms successful completion.
         */
        void CommitPosition(TransportPositionId position);

        /*
         * Return the last canonical position successfully achieved.
         *
         * This provides read-only access to the sequencer's current position
         * without allowing outside code to modify it directly.
         */
        TransportPositionId CurrentPosition() const;

    private:

        /*
         * The last canonical position successfully achieved.
         *
         * This member is private so that other parts of the firmware cannot
         * arbitrarily change Transport's understanding of where the system is.
         */
        TransportPositionId currentPosition;
    };
}

#endif /* TRANSPORTSEQUENCER_H_ */