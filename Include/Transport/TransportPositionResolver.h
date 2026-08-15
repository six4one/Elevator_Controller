/*
 * TransportPositionResolver.h
 *
 * Purpose:
 *     Converts a semantic Transport position into the physical motor
 *     pulse targets required to realize that stable state.
 *
 * Important architectural boundary:
 *     TransportPositions.cpp owns the semantic choreography.
 *     Elevator_Params.h owns the physical geometry and pulse conversions.
 *     This class is the bridge between those two representations.
 *
 *     This class does NOT command motors.
 */

#ifndef TRANSPORTPOSITIONRESOLVER_H_
#define TRANSPORTPOSITIONRESOLVER_H_

#include <stdint.h>
#include "TransportTypes.h"

struct TransportMotorPositions
{
    uint32_t cab;
    uint32_t doorX;
    uint32_t doorY;
};

namespace Transport
{
    class TransportPositionResolver
    {
    public:
        bool Resolve(TransportPositionId position,
                     TransportMotorPositions& result) const;

    private:
        bool ResolveCab(CabPosition position, uint32_t& pulses) const;
        bool ResolveDoorX(DoorXPosition position, uint32_t& pulses) const;
        bool ResolveDoorY(DoorYPosition position, uint32_t& pulses) const;
    };
}

#endif /* TRANSPORTPOSITIONRESOLVER_H_ */