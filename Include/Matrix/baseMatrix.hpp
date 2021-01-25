#pragma once

#include <array>
#include <ostream>

namespace Solid
{

/**
 * @brief Base class for matrix. Musn't be instancied, but only inherited.
 *
 * @tparam ROW Number of row.
 * @tparam COL Number of columns.
 * @tparam TYPE Type of value stored. Default = float
*/
    template<size_t ROW, size_t COL, typename TYPE = float>
    class BaseMatrix
    {
    protected:
        using SelfType = BaseMatrix<ROW, COL, TYPE>;
        using Type = TYPE;

        std::array<TYPE, ROW * COL> data = {};

    public:
#pragma region Constructor

        constexpr BaseMatrix() = default;

        constexpr BaseMatrix(const std::array<TYPE, ROW * COL> &_numbers);

#pragma endregion

#pragma region Static methods

        /**
         * @brief Return the number of row
         * @return number of row
         */
        inline static constexpr size_t getNbRow() noexcept;

        /**
         * @brief Return the number of column
         * @return number of column
         */
        inline static constexpr size_t getNbColumn() noexcept;

        /**
         * @brief Return the number of elements
         * @return number of elements
         */
        inline static constexpr size_t getNbElements() noexcept;

        /**
         * @brief Return transposed matrix
         * @param _mat Matrix to transpose
         * @return matrix transposed
         */
        inline static constexpr BaseMatrix<COL, ROW, TYPE> getTransposed(const SelfType &_mat) noexcept;

        /**
         * @brief Return added matrix
         * @param _mat1 First matrix to add
         * @param _mat2 First matrix to add with
         * @return the computed matrix
         */
        inline static constexpr SelfType getAdd(const SelfType &_mat1, const SelfType &_mat2) noexcept;

        /**
         * @brief Return subtracted matrix
         * @param _mat1 First matrix to subtract
         * @param _mat2 Second matrix to subtract with
         * @return the computed matrix
         */
        inline static constexpr SelfType getSubtract(const SelfType &_mat1, const SelfType &_mat2) noexcept;

        /**
         * @brief Return multiplied matrix
         * @tparam OTHER_ROW Number of row of the second matrix
         * @tparam OTHER_COL Number of column of the second matrix
         * @param _mat1 First matrix to multiply
         * @param _mat2 Second matrix to multiply with
         * @return the computed matrix
         */
        template<size_t OTHER_ROW, size_t OTHER_COL, std::enable_if_t<COL == OTHER_ROW, bool> = true>
        inline static constexpr BaseMatrix<ROW, OTHER_COL, TYPE>
        getMultiplied(const SelfType &_mat1, const BaseMatrix<OTHER_ROW, OTHER_COL, TYPE> &_mat2) noexcept;

        /**
         * @brief Return a sub-matrix of the main matrix
         * @param _mat The main matrix
         * @param _excludedRow Row to exclude
         * @param _excludedCol Col to exclude
         * @return the sub-matrix
         */
        inline static constexpr BaseMatrix<ROW - 1, COL - 1>
        getSubMatrix(const SelfType &_mat, const size_t _excludedRow, const size_t _excludedCol) noexcept;

#pragma endregion

#pragma region Methods

        /**
         * @brief Add self with given matrix
         * @param _mat The matrix to add
         * @return self
         */
        constexpr SelfType &add(const SelfType &_mat) noexcept;

        /**
         * @brief Subtract self with given matrix
         * @param _mat The matrix to subtract
         * @return self
         */
        constexpr SelfType &substract(const SelfType &_mat) noexcept;

        /**
         * @brief Return the value of the matrix in row and column
         * @param _row The row of matrix
         * @param _col The column of matrix
         * @return the corresponding value
         */
        constexpr Type at(const size_t _row, const size_t _col) const noexcept;

        /**
         * @brief Return the value of the matrix at index
         * @param _index The index of value in the matrix
         * @return the corresponding value
         */
        constexpr Type at(const size_t _index) const noexcept;

        /**
         * @brief Return the referenced value of the matrix in row and column
         * @param _row The row of matrix
         * @param _col The column of matrix
         * @return the corresponding value
         */
        constexpr Type &at(const size_t _row, const size_t _col) noexcept;

        /**
         * @brief Return the referenced value of the matrix at index
         * @param _index The index of value in the matrix
         * @return the corresponding value
         */
        constexpr Type &at(const size_t _index) noexcept;

        /**
         * @brief Return the data stored in memory at specified index
         * @param _index The index of value in memory
         * @return the corresponding value
         */
        constexpr Type &getData(const size_t _index) noexcept;

        /**
         * @brief Return the pointer of the first data of the matrix
         * @return the pointer of the first data of the matrix
         */
        constexpr Type *getData() noexcept;

        /**
         * @brief Put the value of the matrix in string
         * @return the string with the value formatted
         */
        std::string toString() const noexcept;

#pragma endregion

#pragma region Operator

        constexpr SelfType operator+(const SelfType &_mat) const noexcept;

        constexpr SelfType operator-(const SelfType &_mat) const noexcept;

        constexpr SelfType &operator+=(const SelfType &_mat) noexcept;

        constexpr SelfType &operator-=(const SelfType &_mat) noexcept;

#pragma endregion
    };

} // !namespace

#include "baseMatrix.inl"

template<size_t ROW, size_t COL, typename TYPE = float>
std::ostream& operator<<(std::ostream& in_stream, const Solid::BaseMatrix<ROW, COL, TYPE>& _mat)
{
    for (size_t i = 0ull; i < ROW; i++)
    {
        in_stream << '[';
        for (size_t j = 0ull; j < COL; j++)
        {
            in_stream << _mat.at(i, j);
            if (j != _mat.getNbColumn() - 1)
                in_stream << ',';
        }
        in_stream << ']' << '\n';
    }

    return in_stream;
}