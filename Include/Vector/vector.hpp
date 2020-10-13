#pragma once

#include "baseVector.hpp"

template<size_t DIM, typename TYPE = float>
class sVect : public BaseVector<DIM,TYPE>
{
public:
	constexpr sVect() {};
	constexpr sVect(const sVect& _copy);
	constexpr sVect(const TYPE& _value);
	constexpr sVect(const BaseVector<DIM,TYPE>& _copy);

	constexpr sVect& operator=(const sVect& _vect) noexcept;
    constexpr sVect& operator=(const BaseVector<DIM,TYPE>& _copy) noexcept;
};

#include "vector.inl"