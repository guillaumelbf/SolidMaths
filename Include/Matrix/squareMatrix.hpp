//TODO: Find how to compute determing for matrix > 4*4
#pragma once

#include "baseMatrix.hpp"

/**
 * @brief Base square matrix class
 * @tparam SIZE Number of row and col
 * @tparam TYPE Type of data
 */
template <size_t SIZE, typename TYPE = float>
class sSquareMat : public BaseMatrix<SIZE, SIZE, TYPE>
{
protected:

    using SelfType = sSquareMat<SIZE, TYPE>;
    using Type = TYPE;

public:
    constexpr sSquareMat() {};
    constexpr sSquareMat(const sSquareMat& _copy);
    constexpr sSquareMat(const TYPE& _value);
    constexpr sSquareMat(const BaseMatrix<SIZE,SIZE,TYPE>& _copy);

#pragma region Static methods

    /**
     * @brief Return the identity matrix
     * @return matrix identity
     */
    static constexpr sSquareMat identity();

#pragma endregion

#pragma region Methods
    /**
     * @brief Transpose the matrix
     * @return self
     */
    constexpr SelfType& transpose() noexcept;

    /**
     * @brief Compute the inverted matrix
     * @return the matrix inverted
     */
    constexpr SelfType getInverted() const noexcept;

#pragma endregion

#pragma region Operator

    constexpr sSquareMat& operator=(const sSquareMat& _mat) noexcept;
    constexpr sSquareMat& operator=(const BaseMatrix<SIZE,SIZE,TYPE>& _copy) noexcept;

#pragma endregion

    constexpr float cofactor(const size_t _row, const size_t _col) const noexcept;
    constexpr SelfType getConjugated() const noexcept;
    constexpr float determining2x2(const int index1,const int index2,const int index3,const int index4) const noexcept;
    constexpr float determining() const noexcept;

};

#include "squareMatrix.inl"