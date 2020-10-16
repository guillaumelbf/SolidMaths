#pragma once

#include <array>

/**
 * @brief Base class for vector with N dimension. Musn't be instancied, but only inherited.
 *
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
    /**
     * @brief Linear interpolation between a start vector to end vector with ratio
     * @param _vect1 Start vector
     * @param _vect2 End vector
     * @param _ratio Ratio value (between 0 and 1)
     * @return the vector result computed
     */
	static constexpr SelfType lerp(const SelfType& _vect1, const SelfType& _vect2, float _ratio) noexcept;

	/**
	 * @brief Spherical linear interpolation between a start vector to end vector with ratio
	 * @param _vect1 Start vector
	 * @param _vect2 End vector
	 * @param _ratio Ratio value (between 0 and 1)
	 * @return the vector result computed
	 */
	static constexpr SelfType slerp(const SelfType& _vect1, const SelfType& _vect2, float _ratio) noexcept;

	/**
	 * @brief Cross product the first vector param with the second
	 * @param _vect1 First vector
	 * @param _vect2 Second vector
	 * @return the vector result computed
	 */
	static constexpr SelfType cross(const SelfType& _vect1, const SelfType& _vect2) noexcept;

	/**
	 * @brief Dot product 
	 * @param _vect1
	 * @param _vect2
	 * @return
	 */
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

	virtual std::string toString() const noexcept;

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

template <size_t DIM, typename TYPE = float>
std::ostream & operator<<(std::ostream & inout_stream, BaseVector<DIM, TYPE> const& _vect)
{
    inout_stream << '[';
    for (size_t i = 0; i < DIM; i++)
    {
        inout_stream << _vect[i];
        if(i != DIM-1){inout_stream << ',';}
    }
    inout_stream << ']';
    return inout_stream;
}