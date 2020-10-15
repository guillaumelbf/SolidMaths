#include "numerics.hpp"

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