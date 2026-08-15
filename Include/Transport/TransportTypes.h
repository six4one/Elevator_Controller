/*
 * TransportTypes.h
 *
 * Created: 2026-08-15
 * Author: admin
 */

#ifndef TRANSPORTTYPES_H_
#define TRANSPORTTYPES_H_

#include <stdint.h>

enum class TransportPositionId
{
    Basement,
    BasementDocked,
    BasementStaging,
    Garage,
    GarageDocked,
    GarageStaging,
    Main,
    Apartment
};

enum class CabPosition
{
    Basement,
    BasementStaging,
    Garage,
    GarageStaging,
    Main,
    Apartment
};

enum class DoorXPosition
{
    XDocked,
    BasementStaging,
    Garage,
    GarageStaging,
    Main,
    Apartment
};

enum class DoorYPosition
{
    YDocked,
    GarageStaging,
    Main,
    Apartment
};

struct LevelSignature
{
    bool basement;
    bool garage;
    bool main;
    bool apartment;
};

struct TransportPosition
{
    TransportPositionId id;

    CabPosition cab;
    DoorXPosition doorX;
    DoorYPosition doorY;

    LevelSignature expectedLevel;

    bool passThru;
};

#endif /* TRANSPORTTYPES_H_ */