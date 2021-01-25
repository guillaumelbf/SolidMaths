#pragma once

#include "squareMatrix.hpp"

namespace Solid
{

    template<typename TYPE = float>
    class Mat3 : public SquareMat<3, TYPE>
    {
    public:

        constexpr Mat3() noexcept = default;
        constexpr Mat3(const Mat3 &_copy) noexcept = default;
        constexpr Mat3(Mat3&& _copy) noexcept = default;

        constexpr Mat3(const TYPE &_value);

        constexpr Mat3(const BaseMatrix<3, 3, TYPE> &_copy);

        constexpr Mat3(const SquareMat<3, TYPE> &_copy);

        constexpr Mat3 &operator=(const Mat3 &_mat) noexcept;

        constexpr Mat3 &operator=(const BaseMatrix<3, 3, TYPE> &_copy) noexcept;

        constexpr Mat3 &operator=(const SquareMat<3, TYPE> &_copy) noexcept;
    };

} //!namespace

#include "matrix3.inl"