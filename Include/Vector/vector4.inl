#include "vector4.hpp"

#define VECTOR_4_TEMPLATE template<typename TYPE> 
#define VECTOR_4 sVect4<TYPE>

VECTOR_4_TEMPLATE
constexpr VECTOR_4::sVect4() : x(this->data[0]), y(this->data[1]), z(this->data[2]), w(this->data[3])
{

}

VECTOR_4_TEMPLATE
constexpr VECTOR_4::sVect4(const sVect4& _copy) : x(this->data[0]), y(this->data[1]), z(this->data[2]), w(this->data[3])
{
	x = _copy.x;
	y = _copy.y;
	z = _copy.z;
	w = _copy.w;
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

VECTOR_4_TEMPLATE
constexpr VECTOR_4::sVect4(const BaseVector<4, TYPE>& _copy) : x(this->data[0]), y(this->data[1]), z(this->data[2])
{
    x = _copy[0];
    y = _copy[1];
    z = _copy[2];
    w = _copy[3];
}

VECTOR_4_TEMPLATE
std::string VECTOR_4::toString() const noexcept
{
    std::string result;

    result = "x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", z: " + std::to_string(z) + ", w: " + std::to_string(w);

    return  result;
}

VECTOR_4_TEMPLATE
constexpr VECTOR_4& VECTOR_4::operator=(const sVect4& _vect) noexcept
{
	x = _vect.x;
	y = _vect.y;
	z = _vect.z;
	w = _vect.w;

	return *this;
}

VECTOR_4_TEMPLATE
constexpr VECTOR_4& VECTOR_4::operator=(const BaseVector<4, TYPE>& _copy) noexcept
{
    x = _copy[0];
    y = _copy[1];
    z = _copy[2];
    w = _copy[3];

    return *this;
}

#undef VECTOR_4_TEMPLATE
#undef VECTOR_4