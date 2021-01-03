#pragma once

#include "baseVector.hpp"

template<size_t DIM, typename TYPE = float>
class sVect : public BaseVector<DIM,TYPE>
{
public:
	constexpr sVect()                   noexcept = default;
	constexpr sVect(const sVect& _copy) noexcept = default;
	constexpr sVect(sVect&& _move)      noexcept = default;
	constexpr sVect(const TYPE& _value);
	constexpr sVect(const BaseVector<DIM,TYPE>& _copy);

	~sVect() = default;

	constexpr sVect& operator=(const sVect& _vect)                  noexcept = default;
	constexpr sVect& operator=(sVect&& _vect)                       noexcept = default;
    constexpr sVect& operator=(const BaseVector<DIM,TYPE>& _copy)   noexcept;
};

#include "vector.inl"