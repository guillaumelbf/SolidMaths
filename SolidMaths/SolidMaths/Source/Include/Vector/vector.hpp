#pragma once

#include "baseVector.hpp"

template<size_t DIM, typename TYPE = float>
class sVect : public BaseVector<sVect<DIM,TYPE>,DIM,TYPE>
{
public:
	constexpr sVect() {};
	constexpr sVect(const TYPE& _value);
};

#include "vector.inl"