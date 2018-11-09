/**
 * @file fixed16.h
 * @brief Export functions to manipulate fixedpoint numbers with 16 (8+8) bits width
 */

#ifndef NOSTD_FIXED_FIXED16_H_
#define NOSTD_FIXED_FIXED16_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <fixed/private/private.h>

#include <stdint.h>

#define FIXED16_FRACBITS 8

typedef int16_t fixed16_t;

static FIXEDPOINT_INLINE fixed16_t fixed16_abs(fixed16_t x)
{
    return FIXED_ABS(fixed16_t, x);
}

static FIXEDPOINT_INLINE fixed16_t fixed16_mul(fixed16_t a, fixed16_t b)
{
    return FIXED_MUL(fixed16_t, FIXED16_FRACBITS, int32_t, a, b);
}

static FIXEDPOINT_INLINE fixed16_t fixed16_div(fixed16_t a, fixed16_t b)
{
    return FIXED_DIV(fixed16_t, FIXED16_FRACBITS, int32_t, a, b);
}

static FIXEDPOINT_INLINE fixed16_t int_to_fixed16(int val)
{
    return INT_TO_FIXED(fixed16_t, FIXED16_FRACBITS, int32_t, val);
}

static FIXEDPOINT_INLINE fixed16_t double_to_fixed16(double val)
{
    return DOUBLE_TO_FIXED(fixed16_t, FIXED16_FRACBITS, val);
}

static FIXEDPOINT_INLINE double fixed16_to_double(fixed16_t val)
{
    return FIXED_TO_DOUBLE(fixed16_t, FIXED16_FRACBITS, val);
}

#ifdef __cplusplus
}
#endif

#endif /* NOSTD_FIXED_FIXED16_H_ */
