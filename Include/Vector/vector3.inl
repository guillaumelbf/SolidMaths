#include "vector3.hpp"

#define VECTOR_3_TEMPLATE template<typename TYPE> 
#define VECTOR_3 sVect3<TYPE>

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3() : x(this->data[0]), y(this->data[1]), z(this->data[2])
{

}

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3(const sVect3& _copy) : x(this->data[0]), y(this->data[1]), z(this->data[2])
{
	x = _copy.x;
	y = _copy.y;
	z = _copy.z;
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

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3(const BaseVector<3, TYPE>& _copy) : x(this->data[0]), y(this->data[1]), z(this->data[2])
{
    x = _copy[0];
    y = _copy[1];
    z = _copy[2];
}

VECTOR_3_TEMPLATE
constexpr VECTOR_3& VECTOR_3::operator=(const sVect3& _vect) noexcept
{
	x = _vect.x;
	y = _vect.y;
	z = _vect.z;
}

VECTOR_3_TEMPLATE
constexpr VECTOR_3& VECTOR_3::operator=(const BaseVector<3, TYPE>& _copy) noexcept
{
    x = _copy[0];
    y = _copy[1];
    z = _copy[2];

    return *this;
}

#undef VECTOR_3_TEMPLATE
#undef VECTOR_3