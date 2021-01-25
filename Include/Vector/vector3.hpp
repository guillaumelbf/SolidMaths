#pragma once

#include "baseVector.hpp"

namespace Solid
{

    template<typename TYPE = float>
    class Vec3 : public BaseVector<3, TYPE>
    {
    public:
        TYPE &x = data[0];
        TYPE &y = data[1];
        TYPE &z = data[2];

        constexpr Vec3() noexcept = default;

        constexpr Vec3(const Vec3 &_copy) noexcept;

        constexpr Vec3(Vec3 &&_move) noexcept;

        constexpr Vec3(const TYPE &_x, const TYPE &_y, const TYPE &_z);

        constexpr Vec3(const TYPE &_value);

        constexpr Vec3(const BaseVector<3, TYPE> &_copy);

        ~Vec3() = default;

        virtual std::string toString() const noexcept final;

        constexpr Vec3 &operator=(const Vec3 &_vec) noexcept;

        constexpr Vec3 &operator=(Vec3 &&_vec) noexcept;

        constexpr Vec3 &operator=(const BaseVector<3, TYPE> &_copy) noexcept;
    };

} //!namespace

#include "vector3.inl"