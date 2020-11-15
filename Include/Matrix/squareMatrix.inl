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
constexpr SQUARE_MATRIX& SQUARE_MATRIX::transpose() noexcept
{
    *this = getTransposed(*this);

    return *this;
}

SQUARE_MATRIX_TEMPLATE
constexpr SQUARE_MATRIX SQUARE_MATRIX::getInverted() const noexcept
{
    sSquareMat inverted;

    sSquareMat transpConjugate = sSquareMat::getTransposed(this->getConjugated());
    TYPE determining = this->determining();

    if(determining == 0)
        return *this;

    for (size_t i = 0; i < this->getNbElements(); i++)
        inverted.at(i) = (transpConjugate.at(i) / determining);

    return inverted;
}
SQUARE_MATRIX_TEMPLATE
constexpr float SQUARE_MATRIX::cofactor(const size_t _row, const size_t _col) const noexcept
{
    sSquareMat<SIZE-1> subMat = sSquareMat<SIZE>::getSubMatrix(*this,_row,_col);
    return pow(-1, _row + _col) * subMat.determining();
}

SQUARE_MATRIX_TEMPLATE
constexpr SQUARE_MATRIX SQUARE_MATRIX::getConjugated() const noexcept
{
    sSquareMat conjugeted;

    for (size_t i = 0; i < SIZE ; i++)
        for (size_t j = 0; j < SIZE ; j++)
            conjugeted.at(i,j) = this->cofactor(i,j);

    return conjugeted;
}

SQUARE_MATRIX_TEMPLATE
constexpr float SQUARE_MATRIX::determining2x2(const int index1,const int index2,const int index3,const int index4) const noexcept
{
    return this->at(index1) * this->at(index4) - this->at(index3) * this->at(index2);
}

SQUARE_MATRIX_TEMPLATE
constexpr float SQUARE_MATRIX::determining() const noexcept
{
    switch (SIZE)
    {
        case 0:
            return  0;
            break;
        case 1:  // matrice 1*1
            return this->at(0);
            break;
        case 2:  // matrice 2*2
            return determining2x2(0,1,2,3);
            break;
        case 3:  // matrice 3*3
            return this->at(0)*determining2x2(4,5,7,8)-this->at(1)*determining2x2(3,5,6,8)+this->at(2)*determining2x2(3,4,6,7);
            break;
        case 4:  // matrice 4*4
            return  this->at(0) * (this->at(5)*(determining2x2(10,11,14,15))-this->at(6)*determining2x2(9,11,13,15)+this->at(7)*determining2x2(9,10,13,14))
                    - this->at(1) * (this->at(4)*determining2x2(10,11,14,15)-this->at(6)*determining2x2(8,11,12,15)+this->at(7)*determining2x2(8,10,12,14))
                    + this->at(2) * (this->at(4)*determining2x2(9,11,13,15)-this->at(5)*determining2x2(8,11,12,15)+this->at(7)*determining2x2(8,9,12,13))
                    - this->at(3) * (this->at(4)*determining2x2(9,10,13,14)-this->at(5)*determining2x2(8,10,12,14)+this->at(6)*determining2x2(8,9,12,13));
            break;
        /*default: // matrice superieur a 4*4
            float determinant = 0;
            for (size_t i = 0; i < SIZE; i++)
            {
                sSquareMat<SIZE-1> subMatrix = sSquareMat<SIZE>::getSubMatrix(*this,0,i);
                float det = subMatrix.determining();
                if(i%2)
                    determinant -= this->at(i) * det;
                else
                    determinant += this->at(i) * det;
            }
            return determinant;
            break;*/
    }

    return 0;
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

    return *this;
}

#undef SQUARE_MATRIX_TEMPLATE
#undef SQUARE_MATRIX