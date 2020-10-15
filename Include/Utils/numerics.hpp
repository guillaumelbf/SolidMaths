#pragma once

/**
 * @brief Clamp the value between min and max
 * @tparam TYPE Type of value
 * @param _value Value to clamp
 * @param _min Minimum value
 * @param _max Maximum value
 * @return Clamped value
 */
template <typename TYPE>
constexpr TYPE clamp(TYPE _value, TYPE _min, TYPE _max) noexcept;

/**
 * @brief Linear interpolation between value and destination with a ratio
 * @tparam TYPE Type of value
 * @param _from Current value
 * @param _to Destination value
 * @param _ratio Ration value (Between 0 and 1)
 * @return the new value computed
 */
template <typename TYPE>
constexpr TYPE lerp(TYPE _from, TYPE _to, float _ratio) noexcept;

#include "numerics.inl"