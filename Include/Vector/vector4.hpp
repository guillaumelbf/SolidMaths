#pragma once

#include "baseVector.hpp"

namespace Solid
{

    template<typename TYPE = float>
    class Vec4 : public BaseVector<4, TYPE>
    {
    public:
        TYPE &x = data[0];
        TYPE &y = data[1];
        TYPE &z = data[2];
        TYPE &w = data[3];

        constexpr Vec4() noexcept = default;

        constexpr Vec4(const Vec4 &_copy) noexcept;

        constexpr Vec4(Vec4 &&_move) noexcept;

        constexpr Vec4(const TYPE &_x, const TYPE &_y, const TYPE &_z, const TYPE &_w);

        constexpr Vec4(const TYPE &_value);

        constexpr Vec4(const BaseVector<4, TYPE> &_copy);

        ~Vec4() = default;

        virtual std::string toString() const noexcept final;

        constexpr Vec4 &operator=(const Vec4 &_vec) noexcept;

        constexpr Vec4 &operator=(Vec4 &&_vec) noexcept;

        constexpr Vec4 &operator=(const BaseVector<4, TYPE> &_copy) noexcept;
    };

} //!namespace

#include "vector4.inl"