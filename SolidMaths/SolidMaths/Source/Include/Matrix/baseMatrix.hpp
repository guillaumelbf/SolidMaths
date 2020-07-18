#pragma once

#include <array>

/**
 * @brief Base class for matrix and vector. Musn't be instancied, but only inherited.
 *
 * @tparam CHILD Child class.
 * @tparam ROW Number of row.
 * @tparam COL Number of columns.
 * @tparam TYPE Type of value stored. Default = float
*/
template <class CHILD, size_t ROW, size_t COL, typename TYPE = float>
class BaseMatrix
{
public:
	
protected:
	std::array<TYPE, ROW* COL> data = {};

	using SelfType = BaseMatrix<CHILD, ROW, COL, TYPE>;
	using Type = TYPE;

public:

	inline static constexpr size_t getNbRow() noexcept;

	inline static constexpr size_t getNbColumn() noexcept;

	inline static constexpr size_t getNbElements() noexcept;
};

#include "baseMatrix.inl"