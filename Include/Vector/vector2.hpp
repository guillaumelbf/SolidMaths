#pragma once

#include "baseVector.hpp"

namespace Solid
{

    template<typename TYPE = float>
    class Vec2 : public BaseVector<2, TYPE>
    {
    public:

        TYPE &x = data[0];
        TYPE &y = data[1];

        constexpr Vec2() noexcept = default;

        constexpr Vec2(const Vec2 &_copy) noexcept;

        constexpr Vec2(Vec2 &&_move) noexcept;

        constexpr Vec2(const TYPE &_x, const TYPE &_y);

        constexpr Vec2(const TYPE &_value);

        constexpr Vec2(const BaseVector<2, TYPE> &_copy);

        constexpr ~Vec2() = default;

        virtual std::string toString() const noexcept final;

        constexpr Vec2 &operator=(const Vec2 &_vect) noexcept;

        constexpr Vec2 &operator=(Vec2 &&_vect) noexcept;

        constexpr Vec2 &operator=(const BaseVector<2, TYPE> &_copy) noexcept;
    };

} //!namespace

#include "vector2.inl"