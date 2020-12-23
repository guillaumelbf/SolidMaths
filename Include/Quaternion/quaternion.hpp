/**
 * @author Guillaume LEFEBVRE
 */

#pragma once

#include "Vector/vector3.hpp"

/**
 * @brief Quaternion class
 * @tparam TYPE Type of data stored
 */
template <typename TYPE = float>
class sQuaternion
{
private:

    using SelfType = sQuaternion<TYPE>;
    using Type = TYPE;

public:

#pragma region Members

    Type w;
    Type x;
    Type y;
    Type z;

#pragma endregion

#pragma region Constructor

    constexpr sQuaternion() noexcept;
    constexpr sQuaternion(const sQuaternion& _copy);

    /**
     * @brief Create quaternion with value inside
     * @param _w W value
     * @param _x X value
     * @param _y Y value
     * @param _z Z value
     */
    constexpr sQuaternion(Type _w, Type _x, Type _y, Type _z);

    /**
     * @brief Create quaternion with euler axis (in radian)
     * @param _xAxis X axis
     * @param _yAxis Y axis
     * @param _zAxis Z axis
     */
    constexpr sQuaternion(Type _xAxis, Type _yAxis, Type _zAxis);

    /**
     * @brief Create quaternion with euler axis (in radian)
     * @param _vect Vector3 of euler rotation
     */
    constexpr sQuaternion(const sVect3<Type>& _vect);

#pragma endregion

#pragma region Static Methods

    /**
     * @brief Compute the linear interpolation of quaternion with ratio
     * @param _quat1 Start quaternion
     * @param _quat2 End quaternion
     * @param _ratio Ratio of lerp
     * @param shortestPath (Optional) Interpolate with the shortest path or not (Default = true)
     * @return The computed quaternion
     */
    static constexpr SelfType lerp(const SelfType& _quat1, const SelfType& _quat2, float _ratio, bool shortestPath = true) noexcept;

    static constexpr SelfType nlerp(const SelfType& _quat1, const SelfType& _quat2, float _ratio, bool shortestPath = true) noexcept;

    /**
     * @brief Compute the spherical linear interpolation of quaternion with ratio
     * @param _quat1 Start quaternion
     * @param _quat2 End quaternion
     * @param _ratio Ratio of slerp
     * @param shortestPath (Optional) Interpolate with the shortest path or not (Default = true)
     * @return The computed quaternion
     */
    static constexpr SelfType slerp(const SelfType& _quat1, const SelfType& _quat2, float _ratio, bool shortestPath = true) noexcept;

    /**
     * @brief Compute the dot product
     * @param _quat1 First quaternion
     * @param _quat2 Second quaternion
     * @return The value computed
     */
    static constexpr Type dot(const SelfType& _quat1, const SelfType& _quat2) noexcept;

    /**
     * @brief Compute the normalized quaternion
     * @param _quat Quaternion to get normalization
     * @return The quaternion normalized result
     */
    static constexpr SelfType getNormalized(const SelfType& _quat) noexcept;

    /**
     * @brief Compute the inverted quaternion
     * @param _quat Quaternion to get inverse
     * @return The quaternion inverted result
     */
    static constexpr SelfType getInverted(const SelfType& _quat) noexcept;

    /**
     * @brief Compute the addition of two quaternion
     * @param _quat1 First quaternion
     * @param _quat2 Second quaternion
     * @return The quaternion result
     */
    static constexpr SelfType getAdded(const SelfType& _quat1, const SelfType& _quat2) noexcept;

    /**
     * @brief Compute the substraction of two quaternion
     * @param _quat1 First quaternion
     * @param _quat2 Second quaternion
     * @return The quaternion result
     */
    static constexpr SelfType getSubstract(const SelfType& _quat1, const SelfType& _quat2) noexcept;

    /**
     * @brief Compute the multiplication of two quaternion
     * @param _quat1 First quaternion
     * @param _quat2 Second quaternion
     * @return The quaternion result
     */
    static constexpr SelfType getMultiplied(const SelfType& _quat1, const SelfType& _quat2) noexcept;

    static constexpr SelfType getMultiplied(const SelfType& _quat, Type _real) noexcept;

#pragma endregion

#pragma region Methods

    /**
     * @brief Compute the linear interpolation of quaternion with ratio between self and another quaternion
     * @param _quat End quaternion
     * @param _ratio Ratio of lerp
     * @param shortestPath (Optional) Interpolate with the shortest path or not (Default = true)
     * @return Self computed
     */
    constexpr SelfType& lerp(const SelfType& _quat, float _ratio, bool shortestPath = true) noexcept;

    /**
     * @brief Compute the spherical linear interpolation of quaternion with ratio between self and another quaternion
     * @param _quat End quaternion
     * @param _ratio Ratio of slerp
     * @param shortestPath (Optional) Interpolate with the shortest path or not (Default = true)
     * @return Self computed
     */
    constexpr SelfType& slerp(const SelfType& _quat, float _ratio, bool shortestPath = true) noexcept;

    /**
     * @brief Compute the dot product between self and another quaternion
     * @param _quat Second quaternion
     * @return The value computed
     */
    constexpr Type dot(const SelfType& _quat) const noexcept;

    /**
     * @brief Compute normalized quaternion
     * @return Quaternion normalized computed
     */
    constexpr SelfType getNormalized() noexcept;

    /**
     * @brief Normalize self quaternion
     * @return Self normalized
     */
    constexpr SelfType& normalize() noexcept;

    /**
     * @brief Compute square root length of self quaternion
     * @return Value computed
     */
    constexpr Type sqrtLength() const noexcept;

    /**
     * @brief Compute the length of self quaternion
     * @return Value computed
     */
    constexpr Type length() const noexcept;

    /**
     * @brief Compute inversion of self quaternion
     * @return The inverted quaternion computed
     */
    constexpr SelfType getInverted() const noexcept;

    /**
     * @brief Compute the self quaternion
     * @return Self quaternion computed
     */
    constexpr SelfType& invert() noexcept;

    /**
     * @brief Compute the addition between self and another quaternion
     * @param _quat Second quaterion
     * @return The quaternion computed
     */
    constexpr SelfType getAdded(const SelfType& _quat) noexcept;

    /**
     * @brief Compute the addition between self and another quaternion
     * @param _quat Second quaternion
     * @return Self quaternion computed
     */
    constexpr SelfType& add(const SelfType& _quat) noexcept;

    /**
     * @brief Compute the substraction between self and another quaternion
     * @param _quat Second quaternion
     * @return The quaternion computed
     */
    constexpr SelfType getSubstract(const SelfType& _quat) noexcept;

    /**
     * @brief Compute the substraction between self and another quaternion
     * @param _quat Second quaternion
     * @return Self quaternion computed
     */
    constexpr SelfType& substract(const SelfType& _quat) noexcept;

    /**
     * @brief Compute the multiplication between self and another quaternion
     * @param _quat Second quaternion
     * @return The quaternion computed
     */
    constexpr SelfType getMultiplied(const SelfType& _quat) const noexcept;

    /**
     * @brief Compute the multiplication between self and another quaternion
     * @param _quat Second quaternion
     * @return Self quaternion computed
     */
    constexpr SelfType& multiply(const SelfType& _quat) noexcept;


#pragma endregion

#pragma region Constructor

    constexpr SelfType& operator=(const SelfType& _copy) noexcept;

    constexpr bool operator==(const SelfType& _quat) noexcept;

    constexpr SelfType operator+(const SelfType& _quat) const noexcept;

    constexpr SelfType operator-(const SelfType& _quat) const noexcept;

    constexpr SelfType operator*(const SelfType& _quat) const noexcept;

    constexpr SelfType& operator+=(const SelfType& _quat) noexcept;

    constexpr SelfType& operator-=(const SelfType& _quat) noexcept;

    constexpr SelfType& operator*=(const SelfType& _quat) noexcept;

    constexpr SelfType operator*(Type _real) const noexcept;

#pragma endregion
};

#include "quaternion.inl"

template <typename TYPE = float>
std::ostream & operator<<(std::ostream & inout_stream, sQuaternion<TYPE> const& _quat)
{
    inout_stream << "w: " << _quat.w << ", x: " << _quat.x << ", y: " << _quat.y << ", z: " << _quat.z;
    return inout_stream;
}