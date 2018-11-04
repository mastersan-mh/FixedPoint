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
        16,
        int64_t
        > Fixed32;

#endif /* FIXED_FIXED32_HPP_ */
