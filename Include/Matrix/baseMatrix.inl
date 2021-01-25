#include "baseMatrix.hpp"

#include <cassert>
#include <string>

namespace Solid
{

#define BASE_MATRIX_TEMPLATE template<size_t ROW, size_t COL, typename TYPE>
#define BASE_MATRIX BaseMatrix<ROW, COL, TYPE>

#pragma region Constructor

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX::BaseMatrix(const std::array<TYPE, ROW * COL> &_numbers)
    {
        for (int i = 0; i < getNbElements(); ++i)
            this->at(i) = _numbers.at(i);
    }

#pragma endregion

#pragma region Static methods

    BASE_MATRIX_TEMPLATE
    inline constexpr size_t BASE_MATRIX::getNbRow() noexcept
    {
        return ROW;
    }

    BASE_MATRIX_TEMPLATE
    inline constexpr size_t BASE_MATRIX::getNbColumn() noexcept
    {
        return COL;
    }

    BASE_MATRIX_TEMPLATE
    inline constexpr size_t BASE_MATRIX::getNbElements() noexcept
    {
        return ROW * COL;
    }

    BASE_MATRIX_TEMPLATE
    inline constexpr BaseMatrix <COL, ROW, TYPE> BASE_MATRIX::getTransposed(const SelfType &_mat) noexcept
    {
        BaseMatrix <COL, ROW, TYPE> transposed;

        for (size_t i = 0; i < _mat.getNbElements(); i++)
            transposed.at(i) = _mat.data[i];

        return transposed;
    }

    BASE_MATRIX_TEMPLATE
    inline constexpr BASE_MATRIX BASE_MATRIX::getAdd(const BASE_MATRIX &_mat1, const BASE_MATRIX &_mat2) noexcept
    {
        BaseMatrix added;

        for (size_t i = 0; i < added.getNbElements(); i++)
            added.at(i) = _mat1.at(i) + _mat2.at(i);

        return added;
    }

    BASE_MATRIX_TEMPLATE
    inline constexpr BASE_MATRIX BASE_MATRIX::getSubtract(const BASE_MATRIX &_mat1, const BASE_MATRIX &_mat2) noexcept
    {
        BaseMatrix subtract;

        for (size_t i = 0; i < subtract.getNbElements(); i++)
            subtract.at(i) = _mat1.at(i) - _mat2.at(i);

        return subtract;
    }

    BASE_MATRIX_TEMPLATE
    template<size_t OTHER_ROW, size_t OTHER_COL, std::enable_if_t<COL == OTHER_ROW, bool>>
    inline constexpr BaseMatrix <ROW, OTHER_COL, TYPE>
    BASE_MATRIX::getMultiplied(const BASE_MATRIX &_mat1, const BaseMatrix <OTHER_ROW, OTHER_COL, TYPE> &_mat2) noexcept
    {
        BaseMatrix <ROW, OTHER_COL, TYPE> multiplied;

        for (size_t i = 0; i < multiplied.getNbElements(); i++)
        {
            for (size_t j = 0; j < COL; j++)
            {
                multiplied.getData(i) +=
                        _mat1.at(i % multiplied.getNbColumn(), j) * _mat2.at(j, (int) i / _mat2.getNbColumn());
            }
        }

        return multiplied;
    }

    BASE_MATRIX_TEMPLATE
    inline constexpr BaseMatrix<ROW - 1, COL - 1>
    BASE_MATRIX::getSubMatrix(const SelfType &_mat, const size_t _excludedRow, const size_t _excludedCol) noexcept
    {
        BaseMatrix < ROW - 1, COL - 1 > subMatrix;

        size_t index = 0;
        for (size_t i = 0; i < ROW; i++)
        {
            if (i == _excludedRow)
                continue;
            for (size_t j = 0; j < COL; ++j)
            {
                if (j == _excludedCol)
                    continue;
                subMatrix.at(index) = _mat.at(i, j);
                index++;
            }
        }

        return subMatrix;
    }

#pragma endregion

#pragma region Methods

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX &BASE_MATRIX::add(const SelfType &_mat) noexcept
    {
        *this = BaseMatrix::getAdd(*this, _mat);

        return *this;
    }

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX &BASE_MATRIX::substract(const SelfType &_mat) noexcept
    {
        *this = BaseMatrix::getSubtract(*this, _mat);

        return *this;
    }

    BASE_MATRIX_TEMPLATE
    constexpr TYPE BASE_MATRIX::at(const size_t _row, const size_t _col) const noexcept
    {
        return data[ROW * _col + _row];
    }

    BASE_MATRIX_TEMPLATE
    constexpr TYPE BASE_MATRIX::at(const size_t _index) const noexcept
    {
        return at(_index / COL, _index % COL);
    }

    BASE_MATRIX_TEMPLATE
    constexpr TYPE &BASE_MATRIX::at(const size_t _row, const size_t _col) noexcept
    {
        return data[ROW * _col + _row];
    }

    BASE_MATRIX_TEMPLATE
    constexpr TYPE &BASE_MATRIX::at(const size_t _index) noexcept
    {
        return at(_index / COL, _index % COL);
    }

    BASE_MATRIX_TEMPLATE
    constexpr TYPE &BASE_MATRIX::getData(const size_t _index) noexcept
    {
        return data[_index];
    }

    BASE_MATRIX_TEMPLATE
    constexpr TYPE *BASE_MATRIX::getData() noexcept
    {
        return data.data();
    }

    BASE_MATRIX_TEMPLATE
    std::string BASE_MATRIX::toString() const noexcept
    {
        std::string result;

        for (size_t i = 0ull; i < ROW; i++)
        {
            result += '[';
            for (size_t j = 0ull; j < COL; j++)
            {
                result += std::to_string(at(i, j));
                if (j != getNbColumn() - 1)
                    result += ',';
            }
            result += "]\n";
        }

        return result;
    }

#pragma endregion

#pragma region Operator

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX BASE_MATRIX::operator+(const SelfType &_mat) const noexcept
    {
        return BaseMatrix::getAdd(*this, _mat);
    }

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX BASE_MATRIX::operator-(const SelfType &_mat) const noexcept
    {
        return BaseMatrix::getSubtract(*this, _mat);
    }

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX &BASE_MATRIX::operator+=(const SelfType &_mat) noexcept
    {
        return this->add(_mat);
    }

    BASE_MATRIX_TEMPLATE
    constexpr BASE_MATRIX &BASE_MATRIX::operator-=(const SelfType &_mat) noexcept
    {
        return this->substract(_mat);
    }

#pragma endregion

#undef BASE_MATRIX_TEMPLATE
#undef BASE_MATRIX

} //!namespace