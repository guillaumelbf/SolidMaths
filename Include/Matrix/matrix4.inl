#include "matrix4.hpp"

#define MATRIX_4_TEMPLATE template<typename TYPE>
#define MATRIX_4 sMat4<TYPE>

MATRIX_4_TEMPLATE
constexpr MATRIX_4::sMat4(const MATRIX_4& _copy)
{
    for (int i = 0; i < _copy.getNbElements() ; ++i)
        this->at(i) = _copy.at(i);
}

MATRIX_4_TEMPLATE
constexpr MATRIX_4::sMat4(const TYPE& _value)
{
    this->data.fill(_value);
}

MATRIX_4_TEMPLATE
constexpr MATRIX_4::sMat4(const BaseMatrix<4,4,TYPE>& _copy)
{
    for (int i = 0; i < _copy.getNbElements() ; ++i)
        this->at(i) = _copy.at(i);
}

MATRIX_4_TEMPLATE
constexpr MATRIX_4::sMat4(const sSquareMat<4,TYPE>& _copy)
{
    for (int i = 0; i < _copy.getNbElements() ; ++i)
        this->at(i) = _copy.at(i);
}

MATRIX_4_TEMPLATE
constexpr MATRIX_4& MATRIX_4::operator=(const MATRIX_4& _mat) noexcept
{
    for (int i = 0; i < _mat.getNbElements() ; ++i)
        this->at(i) = _mat.at(i);

    return *this;
}

MATRIX_4_TEMPLATE
constexpr MATRIX_4& MATRIX_4::operator=(const BaseMatrix<4,4,TYPE>& _copy) noexcept
{
    for (int i = 0; i < _copy.getNbElements() ; ++i)
        this->at(i) = _copy.at(i);

    return *this;
}

MATRIX_4_TEMPLATE
constexpr MATRIX_4& MATRIX_4::operator=(const sSquareMat<4,TYPE>& _copy) noexcept
{
    for (int i = 0; i < _copy.getNbElements() ; ++i)
        this->at(i) = _copy.at(i);

    return *this;
}

#undef MATRIX_4_TEMPLATE
#undef MATRIX_4