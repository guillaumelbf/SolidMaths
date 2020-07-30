#include "baseMatrix.hpp"

#include <cassert>

#define BASE_MATRIX_TEMPLATE template<size_t ROW, size_t COL, typename TYPE>
#define BASE_MATRIX BaseMatrix<ROW, COL, TYPE>

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
constexpr BaseMatrix<COL, ROW, TYPE> BASE_MATRIX::getTransposed()const noexcept
{
	BaseMatrix<COL, ROW, TYPE> transposed;

	for (size_t i = 0; i < getNbElements() / 2ull; i++)
		transposed[i] = data[getNbElements() - i];

	return transposed;
}

template<size_t ROW, size_t COL, typename TYPE>
template<size_t OTHER_ROW, size_t OTHER_COL, typename OTHER_TYPE, std::enable_if_t<COL == OTHER_ROW,bool>>
constexpr BaseMatrix<ROW, OTHER_COL, TYPE> BaseMatrix<ROW,COL,TYPE>::getMultiplied(const BaseMatrix<OTHER_ROW, OTHER_COL, OTHER_TYPE>& _mat)const noexcept
{
	BaseMatrix<ROW, OTHER_COL, OTHER_TYPE> multiplied;

	for (size_t i = 0; i < multiplied.getNbElements(); i++)
	{
		for (size_t j = 0; i < COL; j++)
		{
			multiplied[i] = (multiplied.at(i) + at(i % multiplied.getNbColum(), j) * _mat.at(j, (int)i / _mat.getNbColum));
		}
	}

	return multiplied;
}

BASE_MATRIX_TEMPLATE
constexpr TYPE BASE_MATRIX::at(const size_t _row, const size_t _col) const noexcept
{
	return data[ROW * _col + _row];
}

BASE_MATRIX_TEMPLATE
constexpr TYPE& BASE_MATRIX::at(const size_t _row, const size_t _col) noexcept
{
	return data[ROW * _col + _row];
}

BASE_MATRIX_TEMPLATE
constexpr TYPE BASE_MATRIX::operator[](const size_t _index) const noexcept
{
	return data[_index];
}

BASE_MATRIX_TEMPLATE
constexpr TYPE& BASE_MATRIX::operator[](const size_t _index) noexcept
{
	return data[_index];
}

#undef BASE_MATRIX_TEMPLATE
#undef BASE_MATRIX