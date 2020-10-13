#pragma once

#include "baseVector.hpp"

template <typename TYPE = float>
class sVect2 : public BaseVector<2, TYPE>
{
public:

	TYPE& x;
	TYPE& y;

	constexpr sVect2();
	constexpr sVect2(const sVect2& _copy);
	constexpr sVect2(const TYPE& _x, const TYPE& _y);
	constexpr sVect2(const TYPE& _value);
	constexpr sVect2(const BaseVector<2, TYPE>& _copy);

	constexpr sVect2& operator=(const sVect2& _vect) noexcept;
	constexpr sVect2& operator=(const BaseVector<2, TYPE>& _copy) noexcept;
};

#include "vector2.inl"