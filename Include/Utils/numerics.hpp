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

/**
 * @brief Convert degrees value into radiant
 * @tparam TYPE Type of data
 * @param _value Value to convert
 * @return value converted in radiant
 */
template <typename TYPE>
constexpr TYPE degToRad(TYPE _value) noexcept;

/**
 * @brief Convert radiant value into degrees
 * @tparam TYPE Type of data
 * @param _value Value to convert
 * @return value  converted in degrees
 */
template <typename TYPE>
constexpr TYPE radToDeg(TYPE _value) noexcept;

#include "numerics.inl"