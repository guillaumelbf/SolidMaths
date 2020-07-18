#include "baseMatrix.hpp"

#include <cassert>

#define BASE_MATRIX_TEMPLATE template<class CHILD, size_t ROW, size_t COL, typename TYPE>
#define BASE_MATRIX BaseMatrix<CHILD, ROW, COL, TYPE>

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

#undef BASE_MATRIX_TEMPLATE
#undef BASE_MATRIX