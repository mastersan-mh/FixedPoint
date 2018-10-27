/**
 * @file fixed32.hpp
 */

#ifndef FIXED_FIXED32_HPP_
#define FIXED_FIXED32_HPP_

#include "fixed32.h"

#include "fixedpoint_private.hpp"

typedef
        FixedPoint
        <
        fixed32_t,
        fixed32_abs,
        fixed32_mul,
        fixed32_to_double,
        double_to_fixed32
        > Fixed32;

#endif /* FIXED_FIXED32_HPP_ */
