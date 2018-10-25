#ifndef FIXEDPOINT_FIXED32_HPP_
#define FIXEDPOINT_FIXED32_HPP_

#include "fixed32.h"

#include "fixedpoint_private.hpp"

typedef
        FixedPoint
        <
        fixed32_t,
        fixed32_mul,
        fixed32_to_double,
        double_to_fixed32
        > Fixed32;


#if 1
class Fixed32_
{
public:
    inline Fixed32_()
    {
        value = 0;
    }

    inline Fixed32_(const Fixed32_ & other_)
    {
        value = other_.value;
    }

    inline Fixed32_(Fixed32_ && other_)
    {
        value = other_.value;
    }

    inline explicit Fixed32_(fixed32_t val_)
    {
        value = val_;
    }

    inline explicit Fixed32_(double val_)
    {
        value = double_to_fixed32(val_);
    }

    inline ~Fixed32_(){}

    /* operators: unary */
    inline const Fixed32_& operator+() const
    {
        return *this;
    }

    inline const Fixed32_& operator-()
    {
        value = -value;
        return *this;
    }

    /* operators: binary */
    inline Fixed32_& operator=(const Fixed32_& right)
    {
        value = right.value;
        return *this;
    }

    inline Fixed32_& operator=(fixed32_t right)
    {
        value = right;
        return *this;
    }

    inline Fixed32_& operator=(double right)
    {
        value = double_to_fixed32(right);
        return *this;
    }

    inline Fixed32_ operator+(const Fixed32_& right) const
    {
        return Fixed32_(value + right.value);
    }

    inline Fixed32_ operator-(const Fixed32_& right) const
    {
        return Fixed32_(value - right.value);
    }

    inline Fixed32_ operator*(const Fixed32_& right)
    {
        return Fixed32_(fixed32_mul(value, right.value));
    }

    inline Fixed32_& operator+=(const Fixed32_& right)
    {
        value += right.value;
        return *this;
    }

    inline Fixed32_& operator-=(const Fixed32_& right)
    {
        value -= right.value;
        return *this;
    }

    inline Fixed32_& operator*=(const Fixed32_& right)
    {
        value = fixed32_mul(value, right.value);
        return *this;
    }

    inline bool operator==(const Fixed32_& right)
    {
        return value == right.value;
    }

    inline bool operator!=(const Fixed32_& right)
    {
        return value != right.value;
    }

    inline bool operator>=(const Fixed32_& right)
    {
        return value >= right.value;
    }

    inline bool operator<=(const Fixed32_& right)
    {
        return value <= right.value;
    }

    inline bool operator>(const Fixed32_& right)
    {
        return value > right.value;
    }

    inline bool operator<(const Fixed32_& right)
    {
        return value < right.value;
    }

    /* methods */
    inline fixed32_t toRawFixed()
    {
        return value;
    }

    inline double toDouble()
    {
        return fixed32_to_double(value);
    }

private:
    fixed32_t value;
};
#endif

#endif /* FIXEDPOINT_FIXED32_HPP_ */
