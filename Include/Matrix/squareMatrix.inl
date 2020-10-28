#include "squareMatrix.hpp"

#define SQUARE_MATRIX_TEMPLATE template<size_t SIZE, typename TYPE>
#define SQUARE_MATRIX sSquareMat<SIZE,TYPE>

SQUARE_MATRIX_TEMPLATE
constexpr SQUARE_MATRIX::sSquareMat(const sSquareMat& _copy)
{
    for (int i = 0; i < _copy.getNbElements() ; ++i)
        this->at(i) = _copy.at(i);
}

SQUARE_MATRIX_TEMPLATE
constexpr SQUARE_MATRIX::sSquareMat(const TYPE& _value)
{
    this->data.fill(_value);
}

SQUARE_MATRIX_TEMPLATE
constexpr SQUARE_MATRIX::sSquareMat(const BaseMatrix<SIZE,SIZE,TYPE>& _copy)
{
    for (int i = 0; i < _copy.getNbElements() ; ++i)
        this->at(i) = _copy.at(i);
}

SQUARE_MATRIX_TEMPLATE
constexpr SQUARE_MATRIX SQUARE_MATRIX::identity()
{
    sSquareMat identityMat;

    for (int i = 0; i < SIZE ; ++i)
        identityMat.at(i,i) = static_cast<TYPE>(1);

    return identityMat;
}

SQUARE_MATRIX_TEMPLATE
constexpr SQUARE_MATRIX& SQUARE_MATRIX::operator=(const sSquareMat& _mat) noexcept
{
    for (int i = 0; i < _mat.getNbElements() ; ++i)
        this->at(i) = _mat.at(i);
}

SQUARE_MATRIX_TEMPLATE
constexpr SQUARE_MATRIX& SQUARE_MATRIX::operator=(const BaseMatrix<SIZE,SIZE,TYPE>& _copy) noexcept
{
    for (int i = 0; i < _copy.getNbElements() ; ++i)
        this->at(i) = _copy.at(i);
}

#undef SQUARE_MATRIX_TEMPLATE
#undef SQUARE_MATRIX