#pragma once

#include <array>
#include <ostream>

namespace Solid
{

    /**
     * @brief Base class for vector with N dimension. Musn't be instancied, but only inherited.
     *
     * @tparam DIM Number of dimension.
     * @tparam TYPE Type of value stored. Default = float.
    */
    template<size_t DIM, typename TYPE = float>
    class BaseVector
    {
    protected:
        std::array<TYPE, DIM> data = {};

        using SelfType = BaseVector<DIM, TYPE>;
        using Type = TYPE;

        constexpr BaseVector() noexcept = default;

        constexpr BaseVector(const BaseVector &_copy) noexcept = default;

        constexpr BaseVector(BaseVector &&_move) noexcept = default;

        ~BaseVector() = default;

    public:

#pragma region Static Methods

        /**
         * @brief Linear interpolation between a start vector to end vector with ratio
         * @param _vec1 Start vector
         * @param _vec2 End vector
         * @param _ratio Ratio value (between 0 and 1)
         * @return the vector result computed
         */
        static constexpr SelfType lerp(const SelfType &_vec1, const SelfType &_vec2, float _ratio) noexcept;

        /**
         * @brief Spherical linear interpolation between a start vector to end vector with ratio
         * @param _vec1 Start vector
         * @param _vec2 End vector
         * @param _ratio Ratio value (between 0 and 1)
         * @return the vector result computed
         */
        static constexpr SelfType slerp(const SelfType &_vec1, const SelfType &_vec2, float _ratio) noexcept;

        /**
         * @brief Cross product the first vector param with the second
         * @param _vec1 First vector
         * @param _vec2 Second vector
         * @return the vector result computed
         */
        static constexpr SelfType cross(const SelfType &_vec1, const SelfType &_vec2) noexcept;

        /**
         * @brief Dot product between 2 vector
         * @param _vec1 First vector
         * @param _vec2 Second vector
         * @return the value result computed
         */
        static constexpr Type dot(const SelfType &_vec1, const SelfType &_vec2) noexcept;

#pragma endregion

#pragma region Methods

        /**
         * @brief Compute the square root of the length of the vector
         * @return the value computed
         */
        constexpr Type sqrtLength() const noexcept;

        /**
         * @brief Compute the length of the vector
         * @return the value computed
         */
        constexpr Type length() const noexcept;

        /**
         * @brief Normalize the vector and return himself
         * @return himself normalized
         */
        constexpr SelfType &normalize() noexcept;

        /**
         * @brief Compute normalized vector and return it
         * @return return new normalized vector
         */
        constexpr SelfType getNormalized() const noexcept;

        /**
         * @brief Add vector with param vector
         * @param _vec the vector to add
         * @return himself computed
         */
        constexpr SelfType &add(const SelfType &_vec) noexcept;

        /**
         * @brief Substract vector with param vector
         * @param _vec the vector to substract
         * @return himself computed
         */
        constexpr SelfType &subtract(const SelfType &_vec) noexcept;

        /**
         * @brief Multiply vector with param vector
         * @param _vec the vector to multiply
         * @return himself computed
         */
        constexpr SelfType &multiply(const SelfType &_vec) noexcept;

        /**
         * @brief Divide vector with param vector
         * @param _vec the vector to divide
         * @return himself computed
         */
        constexpr SelfType &divide(const SelfType &_vec) noexcept;

        /**
         * @brief Add vector with param vector
         * @param _vec the vector to add
         * @return himself computed
         */
        constexpr SelfType &add(const Type &_value) noexcept;

        /**
         * @brief Substract vector with param vector
         * @param _vec the vector to substract
         * @return himself computed
         */
        constexpr SelfType &subtract(const Type &_value) noexcept;

        /**
         * @brief Multiply vector with param vector
         * @param _vec the vector to multiply
         * @return himself computed
         */
        constexpr SelfType &multiply(const Type &_value) noexcept;

        /**
         * @brief Divide vector with param vector
         * @param _vec the vector to devide
         * @return himself computed
         */
        constexpr SelfType &divide(const Type &_value) noexcept;

        /**
         * @brief Return if vector is equals with param vector
         * @param _vec the vector to compare
         * @return true if equals false instead
         */
        constexpr bool isEquals(const SelfType &_vec) const noexcept;

        /**
         * @brief Dot product the vector with param vector
         * @param _vec the vector to dot
         * @return value computed
         */
        constexpr Type dot(const SelfType &_vec) const noexcept;

        /**
         * @brief Cross product the vector with param vector
         * @param _vec the vector to cross
         * @return value computed
         */
        constexpr SelfType cross(const SelfType &_vec) const noexcept;

        /**
         * @brief Put value of the vector in string
         * @return the string with value formatted
         */
        virtual std::string toString() const noexcept;

#pragma endregion

#pragma region Operator

        constexpr SelfType &operator=(const SelfType &_vec) noexcept = default;

        constexpr SelfType &operator=(SelfType &&_vec) noexcept = default;

        constexpr bool operator==(const SelfType &_vec) const noexcept;

        constexpr bool operator!=(const SelfType &_vec) const noexcept;

        constexpr SelfType operator+(const SelfType &_vec) const noexcept;

        constexpr SelfType operator-(const SelfType &_vec) const noexcept;

        constexpr SelfType operator*(const SelfType &_vec) const noexcept;

        constexpr SelfType operator/(const SelfType &_vec) const noexcept;

        constexpr SelfType &operator+=(const SelfType &_vec) noexcept;

        constexpr SelfType &operator-=(const SelfType &_vec) noexcept;

        constexpr SelfType &operator*=(const SelfType &_vec) noexcept;

        constexpr SelfType &operator/=(const SelfType &_vec) noexcept;

        constexpr SelfType operator+(const Type &_value) const noexcept;

        constexpr SelfType operator-(const Type &_value) const noexcept;

        constexpr SelfType operator*(const Type &_value) const noexcept;

        constexpr SelfType operator/(const Type &_value) const noexcept;

        constexpr SelfType &operator+=(const Type &_value) noexcept;

        constexpr SelfType &operator-=(const Type &_value) noexcept;

        constexpr SelfType &operator*=(const Type &_value) noexcept;

        constexpr SelfType &operator/=(const Type &_value) noexcept;

        constexpr Type operator[](const size_t _index) const noexcept;

        constexpr Type &operator[](const size_t _index) noexcept;

#pragma endregion
    };

} //!namespace

#include "baseVector.inl"

template <size_t DIM, typename TYPE = float>
std::ostream & operator<<(std::ostream & inout_stream, Solid::BaseVector<DIM, TYPE> const& _vec)
{
    inout_stream << '[';
    for (size_t i = 0; i < DIM; i++)
    {
        inout_stream << _vec[i];
        if(i != DIM-1){inout_stream << ',';}
    }
    inout_stream << ']';
    return inout_stream;
}