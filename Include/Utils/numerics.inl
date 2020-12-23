#include "numerics.hpp"

#include "constants.hpp"

template <typename TYPE>
constexpr TYPE clamp(TYPE _value, TYPE _min, TYPE _max) noexcept
{
    return (_value < _min) ? _min : (_value > _max) ? _max : _value;
}

template <typename TYPE>
constexpr TYPE lerp(TYPE _from, TYPE _to, float _ratio) noexcept
{
    return _from + (_to - _from) * _ratio;
}

template <typename TYPE>
constexpr TYPE degToRad(TYPE _value) noexcept
{
    return _value * S_PI/180;
}

template <typename TYPE>
constexpr TYPE radToDeg(TYPE _value) noexcept
{
    return _value * 180/S_PI;
}