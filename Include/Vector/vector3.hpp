#pragma once

#include "baseVector.hpp"

template <typename TYPE = float>
class sVect3 : public BaseVector<3, TYPE>
{
public:
	TYPE& x;
	TYPE& y;
	TYPE& z;

	constexpr sVect3();
	constexpr sVect3(const sVect3& _copy);
	constexpr sVect3(const TYPE& _x, const TYPE& _y, const TYPE& _z);
	constexpr sVect3(const TYPE& _value);
	constexpr sVect3(const BaseVector<3, TYPE>& _copy);

	constexpr sVect3& operator=(const sVect3& _vect) noexcept;
    constexpr sVect3& operator=(const BaseVector<3, TYPE>& _copy) noexcept;
};

#include "vector3.inl"