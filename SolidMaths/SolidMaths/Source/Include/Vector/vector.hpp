#pragma once

#include "baseVector.hpp"

template<size_t DIM, typename TYPE = float>
class sVect : public BaseVector<sVect<DIM,TYPE>,DIM,TYPE>
{
public:
	constexpr sVect() {};
	constexpr sVect(const sVect& _copy);
	constexpr sVect(const TYPE& _value);

	constexpr sVect& operator=(const sVect& _vect) noexcept;
};

#include "vector.inl"