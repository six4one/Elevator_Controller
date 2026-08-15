/*
 * TransportSequencer.cpp
 *
 * Created: 2026-08-15 4:46:44 PM
 *  Author: admin
 */ 

#include "Transport/TransportSequencer.h"
#include "Transport/TransportPositions.h"

namespace Transport
{
    /*
     * Constructor definition.
     *
     * The TransportSequencer object begins with its current position set to
     * Basement, which is the first row of the canonical Transport table.
     */
    TransportSequencer::TransportSequencer()
        : currentPosition(TransportPositionId::Basement)
    {
    }

    /*
     * Determine the next canonical position on the route to target.
     *
     * Direction is derived from the ordering of TransportPositionId rather
     * than stored as a separate state variable. This avoids maintaining two
     * pieces of information that could disagree with one another.
     *
     * The enum ordering is intentionally identical to the physical
     * bottom-to-top ordering of CanonicalPositions[].
     */
    TransportPositionId TransportSequencer::Next(TransportPositionId target)
    {
        const uint8_t currentIndex =
            static_cast<uint8_t>(currentPosition);

        const uint8_t targetIndex =
            static_cast<uint8_t>(target);

        if (currentIndex == targetIndex)
        {
            return currentPosition;
        }

        /*
         * Ascending:
         *
         * Move one canonical table row upward from currentPosition.
         *
         * The passThru rule is handled here because the sequencer's job is
         * to determine which stable table row should actually be commanded.
         */
        if (targetIndex > currentIndex)
        {
            uint8_t nextIndex = currentIndex + 1;

            while (nextIndex < targetIndex &&
                   CanonicalPositions[nextIndex].passThru)
            {
                ++nextIndex;
            }

            return CanonicalPositions[nextIndex].id;
        }

        /*
         * Descending:
         *
         * Move one canonical table row downward from currentPosition.
         *
         * A pass-through level is skipped unless it is the actual
         * destination.
         */
        uint8_t nextIndex = currentIndex - 1;

        while (nextIndex > targetIndex &&
               CanonicalPositions[nextIndex].passThru)
        {
            --nextIndex;
        }

        return CanonicalPositions[nextIndex].id;
    }

    /*
     * Commit a successfully achieved position.
     *
     * This function deliberately does not perform any motor or safety
     * operation. It simply records the new logical Transport position after
     * another part of the system has established that the commanded move
     * actually succeeded.
     */
    void TransportSequencer::CommitPosition(TransportPositionId position)
    {
        currentPosition = position;
    }

    /*
     * Return the sequencer's current logical position.
     *
     * The trailing "const" means this function promises not to modify the
     * TransportSequencer object while answering the question.
     */
    TransportPositionId TransportSequencer::CurrentPosition() const
    {
        return currentPosition;
    }
}