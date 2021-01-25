//TODO: Find how to compute determing for matrix > 4*4
#pragma once

#include "baseMatrix.hpp"
#include "Vector/vector.hpp"

namespace Solid
{

/**
 * @brief Base square matrix class
 * @tparam SIZE Number of row and col
 * @tparam TYPE Type of data
 */
    template<size_t SIZE, typename TYPE = float>
    class SquareMat : public BaseMatrix<SIZE, SIZE, TYPE>
    {

        using SelfType = SquareMat<SIZE, TYPE>;
        using Type = TYPE;

    public:
        constexpr SquareMat() noexcept = default;
        constexpr SquareMat(const SquareMat &_copy) noexcept = default;
        constexpr SquareMat(SquareMat&& _move) noexcept = default;

        constexpr SquareMat(const TYPE &_value);

        constexpr SquareMat(const BaseMatrix <SIZE, SIZE, TYPE> &_copy);

#pragma region Static methods

        /**
         * @brief Return the identity matrix
         * @return matrix identity
         */
        static constexpr SelfType identity() noexcept;

        /**
         * @brief Return multiplied square matrix
         * @param _mat1 First square matrix
         * @param _mat2 Second square matrix
         * @return the computed matrix
         */
        static constexpr SelfType getMultiplied(const SelfType &_mat1, const SelfType &_mat2) noexcept;

        /**
         * @brief Return multiplied vector
         * @param _mat The matrix
         * @param _vect The vector
         * @return the computed vector
         */
        static constexpr Vec <SIZE, TYPE>
        getMultiplied(const SelfType &_mat, const Vec <SIZE, TYPE> &_vec) noexcept;

#pragma endregion

#pragma region Methods

        /**
         * @brief Transpose the matrix
         * @return self
         */
        constexpr SelfType &transpose() noexcept;

        /**
         * @brief Multiply self with another square matrix
         * @param _mat Second matrix
         * @return self computed
         */
        constexpr SelfType &multiply(const SelfType &_mat) noexcept;

        /**
         * @brief Compute the inverted matrix
         * @return the matrix inverted
         */
        constexpr SelfType getInverted() const noexcept;

        constexpr float determining() const noexcept;

    protected:
        constexpr float cofactor(const size_t _row, const size_t _col) const noexcept;

        constexpr SelfType getConjugated() const noexcept;

        constexpr float
        determining2x2(const int index1, const int index2, const int index3, const int index4) const noexcept;

    public:

#pragma endregion

#pragma region Operator

        constexpr SelfType &operator=(const SquareMat &_mat) noexcept;

        constexpr SelfType &operator=(const BaseMatrix <SIZE, SIZE, TYPE> &_copy) noexcept;

        constexpr SelfType operator*(const SelfType &_mat) noexcept;

        constexpr Vec <SIZE, TYPE> operator*(const Vec<SIZE, TYPE> &_vec) noexcept;

#pragma endregion
    };

} //!namespace

#include "squareMatrix.inl"