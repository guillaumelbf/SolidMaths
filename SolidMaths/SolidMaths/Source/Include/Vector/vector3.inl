#include "vector3.hpp"

#define VECTOR_3_TEMPLATE template<typename TYPE> 
#define VECTOR_3 sVect3<TYPE>

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3() : x(this->data[0]), y(this->data[1]), z(this->data[2])
{

}

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3(const TYPE& _x, const TYPE& _y, const TYPE& _z) : x(this->data[0]), y(this->data[1]), z(this->data[2])
{
	x = _x;
	y = _y;
	z = _z;
}

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3(const TYPE& _value) : x(this->data[0]), y(this->data[1]), z(this->data[2])
{
	x = _value;
	y = _value;
	z = _value;
}

#undef VECTOR_3_TEMPLATE
#undef VECTOR_3