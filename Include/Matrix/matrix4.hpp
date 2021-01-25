#pragma once

#include "squareMatrix.hpp"
#include "Vector/vector4.hpp"

namespace Solid
{

    template<typename TYPE = float>
    class Mat4 : public SquareMat<4, TYPE>
    {
    public:

        constexpr Mat4() = default;

        constexpr Mat4(const Mat4 &_copy);

        constexpr Mat4(const TYPE &_value);

        constexpr Mat4(const BaseMatrix<4, 4, TYPE> &_copy);

        constexpr Mat4(const SquareMat<4, TYPE> &_copy);

        constexpr Mat4 &operator=(const Mat4 &_mat) noexcept;

        constexpr Mat4 &operator=(const BaseMatrix<4, 4, TYPE> &_copy) noexcept;

        constexpr Mat4 &operator=(const SquareMat<4, TYPE> &_copy) noexcept;
    };

} //!namespace
#include "matrix4.inl"