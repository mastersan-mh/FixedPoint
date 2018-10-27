/**
 * fixedpoint_private.hpp
 */

#ifndef FIXED_FIXEDPOINT_PRIVATE_HPP_
#define FIXED_FIXEDPOINT_PRIVATE_HPP_

#include "fixedpoint_common.h"

template <
        typename fixed_t,
        fixed_t (*fixed_abs)(fixed_t),
        fixed_t (*fixed_mul)(fixed_t, fixed_t),
        double (*fixed_to_double)(fixed_t),
        fixed_t (*double_to_fixed)(double)
        >
class FixedPoint
{
public:
    FIXEDPOINT_INLINE FixedPoint():
    value(0)
    {
    }

    FIXEDPOINT_INLINE FixedPoint(const FixedPoint & other_) : value(other_.value)
    {
    }

    FIXEDPOINT_INLINE explicit FixedPoint(fixed_t val_): value(val_)
    {
    }

    FIXEDPOINT_INLINE explicit FixedPoint(double val_): value(double_to_fixed(val_))
    {
    }

    FIXEDPOINT_INLINE ~FixedPoint(){}

    /* operators: unary */
    FIXEDPOINT_INLINE const FixedPoint& operator+() const
    {
        return *this;
    }

    FIXEDPOINT_INLINE const FixedPoint operator-() const
    {
        return FixedPoint(-value);
    }

    /* operators: binary */
    FIXEDPOINT_INLINE FixedPoint& operator=(const FixedPoint& right_)
    {
        value = right_.value;
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator=(fixed_t right_)
    {
        value = right_;
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator=(double right_)
    {
        value = double_to_fixed(right_);
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint operator+(const FixedPoint& right_) const
    {
        return FixedPoint(value + right_.value);
    }

    FIXEDPOINT_INLINE FixedPoint operator-(const FixedPoint& right_) const
    {
        return FixedPoint(value - right_.value);
    }

    FIXEDPOINT_INLINE FixedPoint operator*(const FixedPoint& right_) const
    {
        return FixedPoint(fixed_mul(value, right_.value));
    }

    FIXEDPOINT_INLINE FixedPoint& operator+=(const FixedPoint& right_)
    {
        value += right_.value;
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator-=(const FixedPoint& right_)
    {
        value -= right_.value;
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator*=(const FixedPoint& right_)
    {
        value = fixed_mul(value, right_.value);
        return *this;
    }

    FIXEDPOINT_INLINE bool operator==(const FixedPoint& right_)
    {
        return value == right_.value;
    }

    FIXEDPOINT_INLINE bool operator!=(const FixedPoint& right_) const
    {
        return value != right_.value;
    }

    FIXEDPOINT_INLINE bool operator>=(const FixedPoint& right_) const
    {
        return value >= right_.value;
    }

    FIXEDPOINT_INLINE bool operator<=(const FixedPoint& right_) const
    {
        return value <= right_.value;
    }

    FIXEDPOINT_INLINE bool operator>(const FixedPoint& right_) const
    {
        return value > right_.value;
    }

    FIXEDPOINT_INLINE bool operator<(const FixedPoint& right_) const
    {
        return value < right_.value;
    }

    /* methods */
    FIXEDPOINT_INLINE FixedPoint abs() const
    {
        return FixedPoint(fixed_abs(value));
    }

    FIXEDPOINT_INLINE void set(const FixedPoint & other_)
    {
        value = other_.value;
    }

    FIXEDPOINT_INLINE void set(fixed_t val_)
    {
        value = val_;
    }

    FIXEDPOINT_INLINE void set(double val_)
    {
        value = double_to_fixed(val_);
    }


    FIXEDPOINT_INLINE fixed_t toRawFixed() const
    {
        return value;
    }

    FIXEDPOINT_INLINE double toDouble() const
    {
        return fixed_to_double(value);
    }

private:
    fixed_t value;
};

#endif /* FIXED_FIXEDPOINT_PRIVATE_HPP_ */
