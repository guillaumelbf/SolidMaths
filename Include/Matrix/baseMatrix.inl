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
inline constexpr BaseMatrix<COL, ROW, TYPE> BASE_MATRIX::getTransposed(const SelfType& _mat) noexcept
{
    BaseMatrix<COL, ROW, TYPE> transposed;

    for (size_t i = 0 ; i < _mat.getNbElements() ; i++)
        transposed.at(i) = _mat.data[i];

    return transposed;
}

BASE_MATRIX_TEMPLATE
template<size_t OTHER_ROW, size_t OTHER_COL, std::enable_if_t<COL == OTHER_ROW,bool>>
inline constexpr BaseMatrix<ROW, OTHER_COL, TYPE> BASE_MATRIX::getMultiplied(const BASE_MATRIX& _mat1,const BaseMatrix<OTHER_ROW, OTHER_COL, TYPE>& _mat2) noexcept
{
    BaseMatrix<ROW, OTHER_COL, TYPE> multiplied;

	for (size_t i = 0; i < multiplied.getNbElements(); i++)
	{
		for (size_t j = 0; j < COL; j++)
		{
			multiplied.at(i) = multiplied.at(i) + _mat1.at(i % multiplied.getNbColumn(), j) * _mat2.at(j, (int)i / _mat2.getNbColumn());
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
constexpr TYPE BASE_MATRIX::at(const size_t _index) const noexcept
{
    return at(_index/COL,_index%COL);
}

BASE_MATRIX_TEMPLATE
constexpr TYPE& BASE_MATRIX::at(const size_t _row, const size_t _col) noexcept
{
	return data[ROW * _col + _row];
}

BASE_MATRIX_TEMPLATE
constexpr TYPE& BASE_MATRIX::at(const size_t _index) noexcept
{
    return at(_index/COL,_index%COL);
}

BASE_MATRIX_TEMPLATE
constexpr TYPE* BASE_MATRIX::getData() const noexcept
{
    return data.data();
}

#undef BASE_MATRIX_TEMPLATE
#undef BASE_MATRIX