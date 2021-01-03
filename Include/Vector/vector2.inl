#include "vector2.hpp"

#define VECTOR_2_TEMPLATE template<typename TYPE> 
#define VECTOR_2 sVect2<TYPE>

VECTOR_2_TEMPLATE
constexpr VECTOR_2::sVect2(const sVect2& _copy) noexcept
{
	x = _copy.x;
	y = _copy.y;
}

VECTOR_2_TEMPLATE
constexpr VECTOR_2::sVect2(sVect2&& _move) noexcept
{
    x = std::move(_move.x);
    y = std::move(_move.y);
}

VECTOR_2_TEMPLATE
constexpr VECTOR_2::sVect2(const TYPE& _x, const TYPE& _y)
{
	x = _x;
	y = _y;
}

VECTOR_2_TEMPLATE
constexpr VECTOR_2::sVect2(const TYPE& _value)
{
	x = _value;
	y = _value;
}

VECTOR_2_TEMPLATE
constexpr VECTOR_2::sVect2(const BaseVector<2, TYPE>& _copy)
{
    x = _copy[0];
    y = _copy[1];
}

VECTOR_2_TEMPLATE
std::string VECTOR_2::toString() const noexcept
{
    std::string result;

    result = "x: " + std::to_string(x) + ", y: " + std::to_string(y);

    return  result;
}

VECTOR_2_TEMPLATE
constexpr VECTOR_2& VECTOR_2::operator=(const sVect2& _vect) noexcept
{
	x = _vect.x;
	y = _vect.y;

	return *this;
}

VECTOR_2_TEMPLATE
constexpr VECTOR_2& VECTOR_2::operator=(sVect2&& _vect) noexcept
{
    x = std::move(_vect.x);
    y = std::move(_vect.y);

    return *this;
}

VECTOR_2_TEMPLATE
constexpr VECTOR_2& VECTOR_2::operator=(const BaseVector<2, TYPE>& _copy) noexcept
{
    x = _copy[0];
    y = _copy[1];

    return *this;
}

#undef VECTOR_2_TEMPLATE
#undef VECTOR_2
