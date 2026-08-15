/*
 * TransportPositionResolver.cpp
 *
 * Created: 2026-08-15 5:41:20 PM
 *  Author: admin
 *
 * TransportPositionResolver.cpp
 *
 * Purpose:
 *     Implementation of the semantic-to-physical Transport position
 *     resolver.
 */

#include "Transport/TransportPositionResolver.h"
#include "Transport/TransportPositions.h"
#include "Elevator_Params.h"

namespace Transport
{
    bool TransportPositionResolver::Resolve(
        TransportPositionId position,
        TransportMotorPositions& result) const
    {
        /*
         * Search the canonical table rather than duplicating a second
         * position-to-position mapping here.
         */
        for (uint32_t i = 0; i < CanonicalPositionCount; ++i)
        {
            if (CanonicalPositions[i].id == position)
            {
                const TransportPosition& canonical = CanonicalPositions[i];

                if (!ResolveCab(canonical.cab, result.cab))
                {
                    return false;
                }

                if (!ResolveDoorX(canonical.doorX, result.doorX))
                {
                    return false;
                }

                if (!ResolveDoorY(canonical.doorY, result.doorY))
                {
                    return false;
                }

                return true;
            }
        }

        return false;
    }

    /* Translate the semantic CabPosition into its canonical pulse value. */
    bool TransportPositionResolver::ResolveCab(
        CabPosition position,
        uint32_t& pulses) const
    {
        switch (position)
        {
            case CabPosition::Basement:
                pulses = cabAtBasement_C;
                return true;
            case CabPosition::BasementStaging:
                pulses = cabStagingAtBasement_C;
                return true;
            case CabPosition::Garage:
                pulses = cabAtGarage_C;
                return true;
            case CabPosition::GarageStaging:
                pulses = cabStagingAtGarage_C;
                return true;
            case CabPosition::Main:
                pulses = cabAtMain_C;
                return true;
            case CabPosition::Apartment:
                pulses = cabAtApartment_C;
                return true;
        }
        return false;
    }

    /* Translate the semantic DoorXPosition into its canonical pulse value. */
    bool TransportPositionResolver::ResolveDoorX(
        DoorXPosition position,
        uint32_t& pulses) const
    {
        switch (position)
        {
            case DoorXPosition::XDocked:
                pulses = doorXHome_C;
                return true;
            case DoorXPosition::BasementStaging:
                pulses = doorXStagingAtBasement_C;
                return true;
            case DoorXPosition::Garage:
                pulses = doorXAtGarage_C;
                return true;
            case DoorXPosition::GarageStaging:
                pulses = doorXYStagingAtGarage_C;
                return true;
            case DoorXPosition::Main:
                pulses = doorXYAtMain_C;
                return true;
            case DoorXPosition::Apartment:
                pulses = doorXYAtApartment_C;
                return true;
        }
        return false;
    }

    /* Translate the semantic DoorYPosition into its canonical pulse value. */
    bool TransportPositionResolver::ResolveDoorY(
        DoorYPosition position,
        uint32_t& pulses) const
    {
        switch (position)
        {
            case DoorYPosition::YDocked:
                pulses = doorYHome_C;
                return true;
            case DoorYPosition::GarageStaging:
                pulses = doorXYStagingAtGarage_C;
                return true;
            case DoorYPosition::Main:
                pulses = doorXYAtMain_C;
                return true;
            case DoorYPosition::Apartment:
                pulses = doorXYAtApartment_C;
                return true;
        }
        return false;
    }
}
