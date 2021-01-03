#pragma once

#include "Vector/vector3.hpp"

enum class EAngleUnit
{
    DEGREES,
    RADIANT
};

template<typename TYPE = float>
class sAngle : public sVect3<TYPE>
{
public:
    EAngleUnit angleUnit;

#pragma region Constructors
    
    constexpr sAngle();
    constexpr sAngle(const sAngle& _copy) = default;
    constexpr sAngle(sAngle&& _move) = default;
    ~sAngle() = default;

#pragma endregion

#pragma region Operators

    constexpr sAngle& operator=(const sAngle& _copy) noexcept = default;
    constexpr sAngle& operator=(sAngle&& _move) noexcept = default;

#pragma endregion
    
};

#include "angle.inl"
