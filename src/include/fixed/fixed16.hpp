#ifndef FIXEDPOINT_FIXED16_HPP_
#define FIXEDPOINT_FIXED16_HPP_

#include "fixed16.h"

#include "fixedpoint_private.hpp"

typedef
        FixedPoint
        <
        fixed16_t,
        fixed16_mul,
        fixed16_to_double,
        double_to_fixed16
        > Fixed16;

#endif /* FIXEDPOINT_FIXED16_HPP_ */
