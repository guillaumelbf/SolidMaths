#pragma once

#include "baseVector.hpp"

template <typename TYPE = float>
class sVect3 : public BaseVector<sVect2<TYPE>, 3, TYPE>
{
public:
	TYPE& x;
	TYPE& y;
	TYPE& z;

	constexpr sVect3();
	constexpr sVect3(const TYPE& _x, const TYPE& _y, const TYPE& _z);
	constexpr sVect3(const TYPE& _value);
};

#include "vector3.inl"