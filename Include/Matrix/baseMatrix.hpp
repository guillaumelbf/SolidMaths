#pragma once

#include <iomanip>
#include <array>
#include <ostream>

/**
 * @brief Base class for matrix. Musn't be instancied, but only inherited.
 *
 * @tparam ROW Number of row.
 * @tparam COL Number of columns.
 * @tparam TYPE Type of value stored. Default = float
*/
template <size_t ROW, size_t COL, typename TYPE = float>
class BaseMatrix
{
protected:
	std::array<TYPE, ROW * COL> data = {};
	
	using SelfType = BaseMatrix<ROW, COL, TYPE>;
	using Type = TYPE;

public:

    BaseMatrix() = default;

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
	inline static constexpr BaseMatrix<COL, ROW, TYPE> getTransposed(const SelfType& _mat) noexcept;

	/**
	 * @brief Return multiplied matrix
	 * @tparam OTHER_ROW Number of row of the second matrix
	 * @tparam OTHER_COL Number of column of the second matrix
	 * @param _mat1 First matrix to multiply
	 * @param _mat2 Second matrix to multiply with
	 * @return matrix multiplied
	 */
	template<size_t OTHER_ROW, size_t OTHER_COL, std::enable_if_t<COL == OTHER_ROW,bool> = true>
	inline static constexpr BaseMatrix<ROW, OTHER_COL, TYPE> getMultiplied(const SelfType& _mat1,const BaseMatrix<OTHER_ROW, OTHER_COL, TYPE>& _mat2) noexcept;
#pragma endregion

#pragma region Methods
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
	constexpr Type& at(const size_t _row, const size_t _col) noexcept;
    /**
     * @brief Return the referenced value of the matrix at index
     * @param _index The index of value in the matrix
     * @return the corresponding value
     */
	constexpr Type& at(const size_t _index) noexcept;

	/**
	 * @brief Return the pointer of the first data of the matrix
	 * @return the pointer of the first data of the matrix
	 */
	constexpr Type* getData() const noexcept;

#pragma endregion
};

#include "baseMatrix.inl"

template<size_t ROW, size_t COL, typename TYPE = float>
std::ostream& operator<<(std::ostream& in_stream, const BaseMatrix<ROW, COL, TYPE>& _mat)
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