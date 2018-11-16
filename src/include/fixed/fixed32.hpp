/**
 * @file fixed32.hpp
 * @brief Export class to manipulate fixedpoint numbers with 32 (16+16) bits width
 */

#ifndef NOSTD_FIXED_FIXED32_HPP_
#define NOSTD_FIXED_FIXED32_HPP_

#include <fixed/fixed32.h>

#include <fixed/private/private.hpp>

namespace nostd
{

typedef
        FixedPoint
        <
        fixed32_t,
        16,
        int64_t
        > Fixed32;

}

#endif /* NOSTD_FIXED_FIXED32_HPP_ */