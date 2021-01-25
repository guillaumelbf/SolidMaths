#include "matrix4.hpp"

namespace Solid
{

#define MATRIX_4_TEMPLATE template<typename TYPE>
#define MATRIX_4 Mat4<TYPE>

    MATRIX_4_TEMPLATE
    constexpr MATRIX_4::Mat4(const MATRIX_4 &_copy)
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);
    }

    MATRIX_4_TEMPLATE
    constexpr MATRIX_4::Mat4(const TYPE &_value)
    {
        this->data.fill(_value);
    }

    MATRIX_4_TEMPLATE
    constexpr MATRIX_4::Mat4(const BaseMatrix<4, 4, TYPE> &_copy)
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);
    }

    MATRIX_4_TEMPLATE
    constexpr MATRIX_4::Mat4(const SquareMat<4, TYPE> &_copy)
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);
    }

    MATRIX_4_TEMPLATE
    constexpr MATRIX_4 &MATRIX_4::operator=(const MATRIX_4 &_mat) noexcept
    {
        for (int i = 0; i < _mat.getNbElements(); ++i)
            this->at(i) = _mat.at(i);

        return *this;
    }

    MATRIX_4_TEMPLATE
    constexpr MATRIX_4 &MATRIX_4::operator=(const BaseMatrix<4, 4, TYPE> &_copy) noexcept
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);

        return *this;
    }

    MATRIX_4_TEMPLATE
    constexpr MATRIX_4 &MATRIX_4::operator=(const SquareMat<4, TYPE> &_copy) noexcept
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);

        return *this;
    }

#undef MATRIX_4_TEMPLATE
#undef MATRIX_4

} //!namespace