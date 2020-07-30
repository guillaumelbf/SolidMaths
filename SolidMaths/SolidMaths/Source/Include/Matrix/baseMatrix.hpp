#pragma once

#include <ostream>
#include <iomanip>
#include <array>

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

	BaseMatrix() {}
public:

	inline static constexpr size_t getNbRow() noexcept;

	inline static constexpr size_t getNbColumn() noexcept;

	inline static constexpr size_t getNbElements() noexcept;

	constexpr BaseMatrix<COL, ROW, TYPE> getTransposed()const noexcept;

	template<size_t OTHER_ROW, size_t OTHER_COL, typename OTHER_TYPE, std::enable_if_t<COL == OTHER_ROW,bool> = true>
	constexpr BaseMatrix<ROW, OTHER_COL, TYPE> getMultiplied(const BaseMatrix<OTHER_ROW, OTHER_COL, OTHER_TYPE>& _mat)const noexcept;

	constexpr Type at(const size_t _row, const size_t _col) const noexcept;

	constexpr Type& at(const size_t _row, const size_t _col) noexcept;

	constexpr Type operator[](const size_t _index) const noexcept;

	constexpr Type& operator[](const size_t _index) noexcept;
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