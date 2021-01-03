#pragma once

#include "baseVector.hpp"

template <typename TYPE = float>
class sVect3 : public BaseVector<3, TYPE>
{
public:
	TYPE& x = data[0];
	TYPE& y = data[1];
	TYPE& z = data[2];

	constexpr sVect3()                      noexcept = default;
	constexpr sVect3(const sVect3& _copy)   noexcept;
	constexpr sVect3(sVect3&& _move)        noexcept;
	constexpr sVect3(const TYPE& _x, const TYPE& _y, const TYPE& _z);
	constexpr sVect3(const TYPE& _value);
	constexpr sVect3(const BaseVector<3, TYPE>& _copy);

	~sVect3() = default;

	virtual std::string toString() const noexcept final;

	constexpr sVect3& operator=(const sVect3& _vect) noexcept;
	constexpr sVect3& operator=(sVect3&& _vect) noexcept;
    constexpr sVect3& operator=(const BaseVector<3, TYPE>& _copy) noexcept;
};

#include "vector3.inl"