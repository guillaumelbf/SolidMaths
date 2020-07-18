#include "vector.hpp"

#define VECTOR_TEMPLATE template<size_t DIM, typename TYPE>
#define VECTOR sVect<DIM,TYPE>

VECTOR_TEMPLATE
constexpr VECTOR::sVect(const TYPE& _value)
{
	for (size_t i = 0; i < DIM; i++)
	{
		this->data[i] = _value;
	}
}

#undef VECTOR_TEMPLATE
#undef VECTOR