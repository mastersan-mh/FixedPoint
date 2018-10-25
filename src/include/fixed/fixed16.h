#ifndef FIXEDPOINT_FIXED16_H_
#define FIXEDPOINT_FIXED16_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include "fixedpoint_private.h"

#define FIXED16_FRACBITS 8
#define FIXED16_FRACUNIT ((int16_t)1 << FIXED16_FRACBITS)

typedef int16_t fixed16_t;

FIXEDPOINT_INLINE fixed16_t fixed16_mul(fixed16_t a, fixed16_t b)
{
  return (fixed16_t)((int32_t)a * b >> FIXED16_FRACBITS);
}

FIXEDPOINT_INLINE fixed16_t double_to_fixed16(double val)
{
    return (val * FIXED16_FRACUNIT);
}

FIXEDPOINT_INLINE double fixed16_to_double(fixed16_t val)
{
    return ((double)val / FIXED16_FRACUNIT);
}

#ifdef __cplusplus
}
#endif

#endif /* FIXEDPOINT_FIXED16_H_ */
