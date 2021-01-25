#pragma once

#include "baseVector.hpp"

namespace Solid
{

    template<size_t DIM, typename TYPE = float>
    class Vec : public BaseVector<DIM, TYPE>
    {
    public:
        constexpr Vec() noexcept = default;

        constexpr Vec(const Vec &_copy) noexcept = default;

        constexpr Vec(Vec &&_move) noexcept = default;

        constexpr Vec(const TYPE &_value);

        constexpr Vec(const BaseVector <DIM, TYPE> &_copy);

        ~Vec() = default;

        constexpr Vec &operator=(const Vec &_vec) noexcept = default;

        constexpr Vec &operator=(Vec &&_vec) noexcept = default;

        constexpr Vec &operator=(const BaseVector <DIM, TYPE> &_copy) noexcept;
    };

} //!namespace

#include "vector.inl"