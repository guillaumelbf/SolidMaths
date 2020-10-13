#pragma once

#include <array>

/**
 * @brief Base class for vector with N dimension. Musn't be instancied, but only inherited.
 *
 * @tparam CHILD Child class.
 * @tparam DIM Number of dimension.
 * @tparam TYPE Type of value stored. Default = float.
*/
template <size_t DIM, typename TYPE = float>
class BaseVector
{
protected:
    std::array<TYPE, DIM> data = {};

    using SelfType = BaseVector<DIM, TYPE>;
	using Type = TYPE;

	BaseVector() {}
public:

#pragma region Static Methods
	static constexpr SelfType lerp(const SelfType& _vect1, const SelfType& _vect2, float _ratio) noexcept;

	static constexpr SelfType cross(const SelfType& _vect1, const SelfType& _vect2) noexcept;

	static constexpr Type dot(const SelfType& _vect1, const SelfType& _vect2) noexcept;
#pragma endregion

#pragma region Methods

	constexpr Type sqrtLength() const noexcept;

	constexpr Type length() const noexcept;

	constexpr SelfType& normalize() noexcept;

	constexpr SelfType getNormalized() const noexcept;

	constexpr SelfType& add(const SelfType& _vect) noexcept;

	constexpr SelfType& subtract(const SelfType& _vect) noexcept;
	
	constexpr SelfType& multiply(const SelfType& _vect) noexcept;

	constexpr SelfType& divide(const SelfType& _vect) noexcept;

	constexpr SelfType& add(const Type& _value) noexcept;
	
	constexpr SelfType& subtract(const Type& _value) noexcept;
	
	constexpr SelfType& multiply(const Type& _value) noexcept;
	
	constexpr SelfType& divide(const Type& _value) noexcept;

	constexpr bool isEquals(const SelfType& _vect) const noexcept;

	constexpr Type dot(const SelfType& _vect) const noexcept;

	constexpr SelfType cross(const SelfType& _vect) const noexcept;

#pragma endregion

#pragma region Operator

	constexpr SelfType& operator=(const SelfType& _vect) noexcept;

	constexpr bool operator==(const SelfType& _vect) const noexcept;

	constexpr bool operator!=(const SelfType& _vect) const noexcept;

	constexpr SelfType operator+(const SelfType& _vect) const noexcept;

	constexpr SelfType operator-(const SelfType& _vect) const noexcept;

	constexpr SelfType operator*(const SelfType& _vect) const noexcept;

	constexpr SelfType operator/(const SelfType& _vect) const noexcept;

	constexpr SelfType& operator+=(const SelfType& _vect) noexcept;

	constexpr SelfType& operator-=(const SelfType& _vect) noexcept;

	constexpr SelfType& operator*=(const SelfType& _vect) noexcept;

	constexpr SelfType& operator/=(const SelfType& _vect) noexcept;

	constexpr SelfType operator+(const Type& _value) const noexcept;

	constexpr SelfType operator-(const Type& _value) const noexcept;

	constexpr SelfType operator*(const Type& _value) const noexcept;

	constexpr SelfType operator/(const Type& _value) const noexcept;

	constexpr SelfType& operator+=(const Type& _value) noexcept;

	constexpr SelfType& operator-=(const Type& _value) noexcept;

	constexpr SelfType& operator*=(const Type& _value) noexcept;

	constexpr SelfType& operator/=(const Type& _value) noexcept;

	constexpr Type operator[](const size_t _index) const noexcept;

	constexpr Type& operator[](const size_t _index) noexcept;

#pragma endregion
};

#include "baseVector.inl"