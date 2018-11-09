/**
 * @file fixed32.h
 * @brief Export functions to manipulate fixedpoint numbers with 32 (16+16) bits width
 */

#ifndef FIXED_FIXED32_H_
#define FIXED_FIXED32_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <fixed/private/private.h>

#include <stdint.h>

#define FIXED32_FRACBITS 16

typedef int32_t fixed32_t;

static FIXEDPOINT_INLINE fixed32_t fixed32_abs(fixed32_t x)
{
    return FIXED_ABS(fixed32_t, x);
}

static FIXEDPOINT_INLINE fixed32_t fixed32_mul(fixed32_t a, fixed32_t b)
{
    return FIXED_MUL(fixed32_t, FIXED32_FRACBITS, int64_t, a, b);
}

static FIXEDPOINT_INLINE fixed32_t fixed32_div(fixed32_t a, fixed32_t b)
{
    return FIXED_DIV(fixed32_t, FIXED32_FRACBITS, int64_t, a, b);
}

static FIXEDPOINT_INLINE fixed32_t int_to_fixed32(int val)
{
    return INT_TO_FIXED(fixed32_t, FIXED32_FRACBITS, int64_t, val);
}

static FIXEDPOINT_INLINE fixed32_t double_to_fixed32(double val)
{
    return DOUBLE_TO_FIXED(fixed32_t, FIXED32_FRACBITS, val);
}

static FIXEDPOINT_INLINE double fixed32_to_double(fixed32_t val)
{
    return FIXED_TO_DOUBLE(fixed32_t, FIXED32_FRACBITS, val);
}

#ifdef __cplusplus
}
#endif

#endif /* FIXED_FIXED32_H_ */
