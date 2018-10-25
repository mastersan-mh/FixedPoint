#ifndef FIXEDPOINT_FIXEDPOINT_PRIVATE_HPP_
#define FIXEDPOINT_FIXEDPOINT_PRIVATE_HPP_

template <
        typename fixed_t,
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

    FIXEDPOINT_INLINE FixedPoint(FixedPoint && other_) : value(other_.value)
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

    FIXEDPOINT_INLINE const FixedPoint& operator-()
    {
        value = -value;
        return *this;
    }

    /* operators: binary */
    FIXEDPOINT_INLINE FixedPoint& operator=(const FixedPoint& right)
    {
        value = right.value;
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator=(fixed_t right)
    {
        value = right;
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator=(double right)
    {
        value = double_to_fixed(right);
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint operator+(const FixedPoint& right) const
    {
        return FixedPoint(value + right.value);
    }

    FIXEDPOINT_INLINE FixedPoint operator-(const FixedPoint& right) const
    {
        return FixedPoint(value - right.value);
    }

    FIXEDPOINT_INLINE FixedPoint operator*(const FixedPoint& right)
    {
        return FixedPoint(fixed_mul(value, right.value));
    }

    FIXEDPOINT_INLINE FixedPoint& operator+=(const FixedPoint& right)
    {
        value += right.value;
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator-=(const FixedPoint& right)
    {
        value -= right.value;
        return *this;
    }

    FIXEDPOINT_INLINE FixedPoint& operator*=(const FixedPoint& right)
    {
        value = fixed_mul(value, right.value);
        return *this;
    }

    FIXEDPOINT_INLINE bool operator==(const FixedPoint& right)
    {
        return value == right.value;
    }

    FIXEDPOINT_INLINE bool operator!=(const FixedPoint& right)
    {
        return value != right.value;
    }

    FIXEDPOINT_INLINE bool operator>=(const FixedPoint& right)
    {
        return value >= right.value;
    }

    FIXEDPOINT_INLINE bool operator<=(const FixedPoint& right)
    {
        return value <= right.value;
    }

    FIXEDPOINT_INLINE bool operator>(const FixedPoint& right)
    {
        return value > right.value;
    }

    FIXEDPOINT_INLINE bool operator<(const FixedPoint& right)
    {
        return value < right.value;
    }

    /* methods */
    FIXEDPOINT_INLINE fixed_t toRawFixed()
    {
        return value;
    }

    FIXEDPOINT_INLINE double toDouble()
    {
        return fixed_to_double(value);
    }

private:
    fixed_t value;
};

#endif /* FIXEDPOINT_FIXEDPOINT_PRIVATE_HPP_ */
