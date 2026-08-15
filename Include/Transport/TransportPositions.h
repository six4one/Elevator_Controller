/*
 * TransportPositions.h
 *
 * Created: 2026-08-15
 * Author: admin
 */

#ifndef TRANSPORTPOSITIONS_H_
#define TRANSPORTPOSITIONS_H_

#include <stdint.h>
#include "TransportTypes.h"

namespace Transport
{
    struct MotorPosition
    {
        uint32_t cab;
        uint32_t doorX;
        uint32_t doorY;
    };

    extern const TransportPosition CanonicalPositions[];
    extern const uint32_t CanonicalPositionCount;

    MotorPosition ResolveMotorPosition(const TransportPosition& position);
}

#endif /* TRANSPORTPOSITIONS_H_ */