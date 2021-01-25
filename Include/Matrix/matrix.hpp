#pragma once

#include "baseMatrix.hpp"

namespace Solid
{

    template<size_t ROW, size_t COL, typename TYPE = float>
    class Mat : public BaseMatrix<ROW, COL, TYPE>
    {
    public:
        constexpr Mat()
        {};

        constexpr Mat(const Mat &_copy);

        constexpr Mat(const TYPE &_value);

        constexpr Mat(const BaseMatrix<ROW, COL, TYPE> &_copy);

        constexpr Mat &operator=(const Mat &_mat) noexcept;

        constexpr Mat &operator=(const BaseMatrix<ROW, COL, TYPE> &_copy) noexcept;
    };

} //!namespace

#include "matrix.inl"