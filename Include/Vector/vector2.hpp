#pragma once

#include "baseVector.hpp"

template <typename TYPE = float>
class sVect2 : public BaseVector<2, TYPE>
{
public:

	TYPE& x = data[0];
	TYPE& y = data[1];

	constexpr sVect2()                      noexcept = default;
	constexpr sVect2(const sVect2& _copy)   noexcept;
	constexpr sVect2(sVect2&& _move)        noexcept;
	constexpr sVect2(const TYPE& _x, const TYPE& _y);
	constexpr sVect2(const TYPE& _value);
	constexpr sVect2(const BaseVector<2, TYPE>& _copy);

	constexpr ~sVect2() = default;

    virtual std::string toString() const noexcept final;

	constexpr sVect2& operator=(const sVect2& _vect) noexcept;
	constexpr sVect2& operator=(sVect2&& _vect) noexcept;
	constexpr sVect2& operator=(const BaseVector<2, TYPE>& _copy) noexcept;
};

#include "vector2.inl"