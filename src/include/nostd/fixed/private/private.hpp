/**
 * @file private.hpp
 */

#ifndef NOSTD_FIXED_PRIVATE_PRIVATE_HPP_
#define NOSTD_FIXED_PRIVATE_PRIVATE_HPP_

#include <nostd/fixed/private/common.h>
#include <nostd/fixed/private/private.h>

namespace nostd
{

template <
        typename Tfixed_t,
        unsigned char Tfracbits,
        typename Tenclosingtype_t
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

    FIXEDPOINT_INLINE explicit FixedPoint(Tfixed_t val_): value(val_)
    {
    }

    FIXEDPOINT_INLINE explicit FixedPoint(double val_): value(DOUBLE_TO_FIXED(Tfixed_t, Tfracbits, val_))
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

    FIXEDPOINT_INLINE FixedPoint& operator=(Tfixed_t right_)
    {
        value = right_;
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator=(double right_)
    {
        value = DOUBLE_TO_FIXED(Tfixed_t, Tfracbits, right_);
        return *this;
    }

    /* <FixedPoint> <op> <FixedPoint> */
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
        return FixedPoint(FIXED_MUL(Tfixed_t, Tfracbits, Tenclosingtype_t, value, right_.value));
    }

    FIXEDPOINT_INLINE FixedPoint operator/(const FixedPoint& right_) const
    {
        return FixedPoint(FIXED_DIV(Tfixed_t, Tfracbits, Tenclosingtype_t, value, right_.value));
    }

    /* <FixedPoint> <op>= <FixedPoint> */
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
        value = FIXED_MUL(Tfixed_t, Tfracbits, Tenclosingtype_t, value, right_.value);
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator/=(const FixedPoint& right_)
    {
        value = FIXED_DIV(Tfixed_t, Tfracbits, Tenclosingtype_t, value, right_.value);
        return *this;
    }

    /* <FixedPoint> <eq-op> <FixedPoint> */
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
    FIXEDPOINT_INLINE void setRawFixed(Tfixed_t val_)
    {
        value = val_;
    }

    FIXEDPOINT_INLINE void set(const FixedPoint & other_)
    {
        value = other_.value;
    }

    FIXEDPOINT_INLINE void set(double val_)
    {
        value = DOUBLE_TO_FIXED(Tfixed_t, Tfracbits, val_);
    }

    FIXEDPOINT_INLINE void set(int val_)
    {
        value = INT_TO_FIXED(Tfixed_t, Tfracbits, Tenclosingtype_t, val_);
    }

    FIXEDPOINT_INLINE Tfixed_t toRawFixed() const
    {
        return value;
    }

    FIXEDPOINT_INLINE double toDouble() const
    {
        return FIXED_TO_DOUBLE(Tfixed_t, Tfracbits, value);
    }

    FIXEDPOINT_INLINE FixedPoint toAbs() const
    {
        return FixedPoint(FIXED_ABS(Tfixed_t, value));
    }

private:
    Tfixed_t value;
};

}

#endif /* NOSTD_FIXED_PRIVATE_PRIVATE_HPP_ */
