#include "vector3.hpp"

#define VECTOR_3_TEMPLATE template<typename TYPE> 
#define VECTOR_3 sVect3<TYPE>

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3(const sVect3& _copy) noexcept
{
	x = _copy.x;
	y = _copy.y;
	z = _copy.z;
}

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3(sVect3&& _move) noexcept
{
    x = std::move(_move.x);
    y = std::move(_move.y);
    z = std::move(_move.z);
}

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3(const TYPE& _x, const TYPE& _y, const TYPE& _z)
{
	x = _x;
	y = _y;
	z = _z;
}

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3(const TYPE& _value)
{
	x = _value;
	y = _value;
	z = _value;
}

VECTOR_3_TEMPLATE
constexpr VECTOR_3::sVect3(const BaseVector<3, TYPE>& _copy)
{
    x = _copy[0];
    y = _copy[1];
    z = _copy[2];
}

VECTOR_3_TEMPLATE
std::string VECTOR_3::toString() const noexcept
{
    std::string result;

    result = "x: " + std::to_string(x) + ", y: " + std::to_string(y) + ", z: " + std::to_string(z);

    return  result;
}

VECTOR_3_TEMPLATE
constexpr VECTOR_3& VECTOR_3::operator=(const sVect3& _vect) noexcept
{
	x = _vect.x;
	y = _vect.y;
	z = _vect.z;

	return *this;
}

VECTOR_3_TEMPLATE
constexpr VECTOR_3& VECTOR_3::operator=(sVect3&& _vect) noexcept
{
    x = std::move(_vect.x);
    y = std::move(_vect.y);
    z = std::move(_vect.z);

    return *this;
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