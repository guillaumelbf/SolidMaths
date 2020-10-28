#pragma once

#include "baseMatrix.hpp"

template <size_t ROW, size_t COL, typename TYPE = float>
class sMat : public BaseMatrix<ROW,COL,TYPE>
{
public:
    constexpr sMat() {};
    constexpr sMat(const sMat& _copy);
    constexpr sMat(const TYPE& _value);
    constexpr sMat(const BaseMatrix<ROW,COL,TYPE>& _copy);

    constexpr sMat& operator=(const sMat& _mat) noexcept;
    constexpr sMat& operator=(const BaseMatrix<ROW,COL,TYPE>& _copy) noexcept;
};

#include "matrix.inl"