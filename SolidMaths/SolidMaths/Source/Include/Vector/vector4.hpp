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
	constexpr sVect4(const TYPE& _x, const TYPE& _y, const TYPE& _z, const TYPE& _w);
	constexpr sVect4(const TYPE& _value);
};

#include "vector4.inl"