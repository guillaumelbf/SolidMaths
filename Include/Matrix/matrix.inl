#include "matrix.hpp"

namespace Solid
{

#define BASE_MATRIX_TEMPLATE template<size_t ROW, size_t COL, typename TYPE>
#define BASE_MATRIX Mat<ROW,COL,TYPE>

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX::Mat(const Mat &_copy)
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);
    }

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX::Mat(const TYPE &_value)
    {
        this->data.fill(_value);
    }

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX::Mat(const BaseMatrix <ROW, COL, TYPE> &_copy)
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);
    }

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX &BASE_MATRIX::operator=(const Mat &_mat) noexcept
    {
        for (int i = 0; i < _mat.getNbElements(); ++i)
            this->at(i) = _mat.at(i);

        return *this;
    }

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX &BASE_MATRIX::operator=(const BaseMatrix <ROW, COL, TYPE> &_copy) noexcept
    {
        for (int i = 0; i < _copy.getNbElements(); ++i)
            this->at(i) = _copy.at(i);

        return *this;
    }

#undef BASE_MATRIX_TEMPLATE
#undef BASE_MATRIX

} //!namespace