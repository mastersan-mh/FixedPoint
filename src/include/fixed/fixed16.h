/**
 * @file fixed16.h
 */

#ifndef FIXED_FIXED16_H_
#define FIXED_FIXED16_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include "fixedpoint_private.h"
#include <stdint.h>

#define FIXED16_BITS 16
#define FIXED16_FRACBITS 8
#define FIXED16_FRACUNIT ((int16_t)1 << FIXED16_FRACBITS)

typedef int16_t fixed16_t;

static FIXEDPOINT_INLINE fixed16_t fixed16_abs(fixed16_t x)
{
    fixed16_t sign = x >> (FIXED16_BITS - 1);
    return (x ^ sign) - sign;
}

static FIXEDPOINT_INLINE fixed16_t fixed16_mul(fixed16_t a, fixed16_t b)
{
  return (fixed16_t)((int32_t)a * b >> FIXED16_FRACBITS);
}

static FIXEDPOINT_INLINE fixed16_t fixed16_div(fixed16_t a, fixed16_t b)
{
  return (fixed16_t)( ((int32_t)a << FIXED16_FRACBITS) / b );
}

static FIXEDPOINT_INLINE fixed16_t int_to_fixed16(int val)
{
    return ((int32_t)val << FIXED16_FRACBITS);
}

static FIXEDPOINT_INLINE fixed16_t double_to_fixed16(double val)
{
    return (val * FIXED16_FRACUNIT);
}

static FIXEDPOINT_INLINE double fixed16_to_double(fixed16_t val)
{
    return ((double)val / FIXED16_FRACUNIT);
}

#ifdef __cplusplus
}
#endif

#endif /* FIXED_FIXED16_H_ */
