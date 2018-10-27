/**
 * @file fixed16.hpp
 */

#ifndef FIXED_FIXED16_HPP_
#define FIXED_FIXED16_HPP_

#include "fixed16.h"

#include "fixedpoint_private.hpp"

typedef
        FixedPoint
        <
        fixed16_t,
        fixed16_abs,
        fixed16_mul,
        fixed16_to_double,
        double_to_fixed16
        > Fixed16;

#endif /* FIXED_FIXED16_HPP_ */
