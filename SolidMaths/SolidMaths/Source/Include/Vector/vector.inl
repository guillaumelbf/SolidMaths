#include "vector.hpp"

#define VECTOR_TEMPLATE template<size_t DIM, typename TYPE>
#define VECTOR sVect<DIM,TYPE>

VECTOR_TEMPLATE
constexpr VECTOR::sVect(const sVect& _copy)
{
	for (size_t i = 0; i < DIM; i++)
		this->data[i] = _copy[i];
}

VECTOR_TEMPLATE
constexpr VECTOR::sVect(const TYPE& _value)
{
	for (size_t i = 0; i < DIM; i++)
		this->data[i] = _value;
}

VECTOR_TEMPLATE
constexpr VECTOR& VECTOR::operator=(const sVect& _vect) noexcept
{
	for (size_t i = 0; i < DIM; i++)
		this->data[i] = _vect[i];

	return *this;
}

#undef VECTOR_TEMPLATE
#undef VECTOR