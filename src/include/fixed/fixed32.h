#ifndef FIXEDPOINT_FIXED32_H_
#define FIXEDPOINT_FIXED32_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <inttypes.h>
#include "fixedpoint_private.h"

#define FIXED32_FRACBITS 16
#define FIXED32_FRACUNIT ((int32_t)1 << FIXED32_FRACBITS)

typedef int32_t fixed32_t;

FIXEDPOINT_INLINE fixed32_t fixed32_mul(fixed32_t a, fixed32_t b)
{
  return (fixed32_t)((int64_t)a * b >> FIXED32_FRACBITS);
}

FIXEDPOINT_INLINE fixed32_t double_to_fixed32(double val)
{
    return (val * FIXED32_FRACUNIT);
}

FIXEDPOINT_INLINE double fixed32_to_double(fixed32_t val)
{
    return ((double)val / FIXED32_FRACUNIT);
}

#ifdef __cplusplus
}
#endif

#endif /* FIXEDPOINT_FIXED32_H_ */
