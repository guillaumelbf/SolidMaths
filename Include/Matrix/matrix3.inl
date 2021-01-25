#include "matrix3.hpp"

namespace Solid
{

#define MATRIX_3_TEMPLATE template<typename TYPE>
#define MATRIX_3 Mat3<TYPE>

    MATRIX_3_TEMPLATE
    constexpr MATRIX_3::Mat3(const TYPE &_value)
    {
        this->data.fill(_value);
    }

    MATRIX_3_TEMPLATE
    constexpr MATRIX_3::Mat3(const BaseMatrix<3, 3, TYPE> &_copy)
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);
    }

    MATRIX_3_TEMPLATE
    constexpr MATRIX_3::Mat3(const SquareMat<3, TYPE> &_copy)
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);
    }

    MATRIX_3_TEMPLATE
    constexpr MATRIX_3 &MATRIX_3::operator=(const MATRIX_3 &_mat) noexcept
    {
        for (int i = 0; i < _mat.getNbElements(); ++i)
            this->at(i) = _mat.at(i);

        return *this;
    }

    MATRIX_3_TEMPLATE
    constexpr MATRIX_3 &MATRIX_3::operator=(const BaseMatrix<3, 3, TYPE> &_copy) noexcept
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);

        return *this;
    }

    MATRIX_3_TEMPLATE
    constexpr MATRIX_3 &MATRIX_3::operator=(const SquareMat<3, TYPE> &_copy) noexcept
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);

        return *this;
    }

#undef MATRIX_3_TEMPLATE
#undef MATRIX_3

} //!namespace