#pragma once

#include "squareMatrix.hpp"

template <typename TYPE = float>
class sMat3 : public sSquareMat<3, TYPE>
{
public:

    constexpr sMat3() {};
    constexpr sMat3(const sMat3& _copy);
    constexpr sMat3(const TYPE& _value);
    constexpr sMat3(const BaseMatrix<3,3,TYPE>& _copy);
    constexpr sMat3(const sSquareMat<3,TYPE>& _copy);

    constexpr sMat3& operator=(const sMat3& _mat) noexcept;
    constexpr sMat3& operator=(const BaseMatrix<3,3,TYPE>& _copy) noexcept;
    constexpr sMat3& operator=(const sSquareMat<3,TYPE>& _copy) noexcept;
};

#include "matrix3.inl"