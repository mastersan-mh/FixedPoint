/*
 * fixed_private.h
 */

#ifndef FIXEDPOINT_FIXEDPOINT_PRIVATE_H_
#define FIXEDPOINT_FIXEDPOINT_PRIVATE_H_

/* #define FIXEDPOINT_DENY_INLINE // */
/* #define FIXEDPOINT_ALLOW_INLINE // */
#define FIXEDPOINT_ALLOW_STRICT_INLINE // */

#if defined(FIXEDPOINT_DENY_INLINE)
#   define FIXEDPOINT_INLINE
#elif defined(FIXEDPOINT_ALLOW_INLINE)
#   define FIXEDPOINT_INLINE inline
#elif defined(FIXEDPOINT_ALLOW_STRICT_INLINE)
#   define FIXEDPOINT_INLINE __attribute__((always_inline)) inline
#endif

#endif /* FIXEDPOINT_FIXEDPOINT_PRIVATE_H_ */
