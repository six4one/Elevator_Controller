/*
 * TransportPositions.cpp
 *
 * Created: 2026-08-15
 * Author: admin
 */

#include "Transport/TransportPositions.h"
#include "Elevator_Params.h"

namespace Transport
{
    const TransportPosition CanonicalPositions[] =
    {
        { TransportPositionId::Basement,
          CabPosition::Basement,
          DoorXPosition::XDocked,
          DoorYPosition::YDocked,
          { true, false, false, false },
          false },

        { TransportPositionId::BasementDocked,
          CabPosition::BasementStaging,
          DoorXPosition::XDocked,
          DoorYPosition::YDocked,
          { true, false, false, false },
          false },

        { TransportPositionId::BasementStaging,
          CabPosition::BasementStaging,
          DoorXPosition::BasementStaging,
          DoorYPosition::YDocked,
          { true, false, false, false },
          false },

        { TransportPositionId::Garage,
          CabPosition::Garage,
          DoorXPosition::Garage,
          DoorYPosition::YDocked,
          { false, true, false, false },
          true },

        { TransportPositionId::GarageDocked,
          CabPosition::GarageStaging,
          DoorXPosition::GarageStaging,
          DoorYPosition::YDocked,
          { false, true, false, false },
          false },

        { TransportPositionId::GarageStaging,
          CabPosition::GarageStaging,
          DoorXPosition::GarageStaging,
          DoorYPosition::GarageStaging,
          { false, true, false, false },
          false },

        { TransportPositionId::Main,
          CabPosition::Main,
          DoorXPosition::Main,
          DoorYPosition::Main,
          { false, false, true, false },
          true },

        { TransportPositionId::Apartment,
          CabPosition::Apartment,
          DoorXPosition::Apartment,
          DoorYPosition::Apartment,
          { false, false, false, true },
          false }
    };

    const uint32_t CanonicalPositionCount =
        sizeof(CanonicalPositions) / sizeof(CanonicalPositions[0]);

    MotorPosition ResolveMotorPosition(const TransportPosition& position)
    {
        MotorPosition result;

        switch (position.cab)
        {
            case CabPosition::Basement:
                result.cab = cabAtBasement_C;
                break;
            case CabPosition::BasementStaging:
                result.cab = cabStagingAtBasement_C;
                break;
            case CabPosition::Garage:
                result.cab = cabAtGarage_C;
                break;
            case CabPosition::GarageStaging:
                result.cab = cabStagingAtGarage_C;
                break;
            case CabPosition::Main:
                result.cab = cabAtMain_C;
                break;
            case CabPosition::Apartment:
                result.cab = cabAtApartment_C;
                break;
        }

        switch (position.doorX)
        {
            case DoorXPosition::XDocked:
                result.doorX = doorXHome_C;
                break;
            case DoorXPosition::BasementStaging:
                result.doorX = doorXStagingAtBasement_C;
                break;
            case DoorXPosition::GarageStaging:
                result.doorX = doorXYStagingAtGarage_C;
                break;
            case DoorXPosition::Garage:
                result.doorX = doorXAtGarage_C;
                break;
            case DoorXPosition::Main:
                result.doorX = doorXYAtMain_C;
                break;
            case DoorXPosition::Apartment:
                result.doorX = doorXYAtApartment_C;
                break;
        }

        switch (position.doorY)
        {
            case DoorYPosition::YDocked:
                result.doorY = doorYHome_C;
                break;
            case DoorYPosition::GarageStaging:
                result.doorY = doorXYStagingAtGarage_C;
                break;
            case DoorYPosition::Main:
                result.doorY = doorXYAtMain_C;
                break;
            case DoorYPosition::Apartment:
                result.doorY = doorXYAtApartment_C;
                break;
        }

        return result;
    }
}