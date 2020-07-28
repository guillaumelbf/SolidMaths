#pragma once

#include "baseVector.hpp"

template <typename TYPE = float>
class sVect4 : public BaseVector<sVect2<TYPE>, 4, TYPE>
{
public:
	TYPE& x;
	TYPE& y;
	TYPE& z;
	TYPE& w;

	constexpr sVect4();
	constexpr sVect4(const sVect4& _copy);
	constexpr sVect4(const TYPE& _x, const TYPE& _y, const TYPE& _z, const TYPE& _w);
	constexpr sVect4(const TYPE& _value);

	constexpr sVect4& operator=(const sVect4& _vect) noexcept;
};

#include "vector4.inl"