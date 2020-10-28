#pragma once

#include "squareMatrix.hpp"

template <typename TYPE = float>
class sMat4 : public sSquareMat<4, TYPE>
{
public:

    constexpr sMat4() {};
    constexpr sMat4(const sMat4& _copy);
    constexpr sMat4(const TYPE& _value);
    constexpr sMat4(const BaseMatrix<4,4,TYPE>& _copy);
    constexpr sMat4(const sSquareMat<4,TYPE>& _copy);

    constexpr sMat4& operator=(const sMat4& _mat) noexcept;
    constexpr sMat4& operator=(const BaseMatrix<4,4,TYPE>& _copy) noexcept;
    constexpr sMat4& operator=(const sSquareMat<4,TYPE>& _copy) noexcept;
};

#include "matrix4.inl"