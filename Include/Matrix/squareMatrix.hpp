#pragma once

#include "baseMatrix.hpp"

template <size_t SIZE, typename TYPE = float>
class sSquareMat : public BaseMatrix<SIZE, SIZE, TYPE>
{
public:
    constexpr sSquareMat() {};
    constexpr sSquareMat(const sSquareMat& _copy);
    constexpr sSquareMat(const TYPE& _value);
    constexpr sSquareMat(const BaseMatrix<SIZE,SIZE,TYPE>& _copy);

    static constexpr sSquareMat identity();

    constexpr sSquareMat& operator=(const sSquareMat& _mat) noexcept;
    constexpr sSquareMat& operator=(const BaseMatrix<SIZE,SIZE,TYPE>& _copy) noexcept;
};

#include "squareMatrix.inl"