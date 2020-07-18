#include "vector4.hpp"

#define VECTOR_4_TEMPLATE template<typename TYPE> 
#define VECTOR_4 sVect4<TYPE>

VECTOR_4_TEMPLATE
constexpr VECTOR_4::sVect4() : x(this->data[0]), y(this->data[1]), z(this->data[2]), w(this->data[3])
{

}

VECTOR_4_TEMPLATE
constexpr VECTOR_4::sVect4(const TYPE& _x, const TYPE& _y, const TYPE& _z, const TYPE& _w) : x(this->data[0]), y(this->data[1]), z(this->data[2]), w(this->data[3])
{
	x = _x;
	y = _y;
	z = _z;
	w = _w;
}

VECTOR_4_TEMPLATE
constexpr VECTOR_4::sVect4(const TYPE& _value) : x(this->data[0]), y(this->data[1]), z(this->data[2]), w(this->data[3])
{
	x = _value;
	y = _value;
	z = _value;
	w = _value;
}

#undef VECTOR_4_TEMPLATE
#undef VECTOR_4