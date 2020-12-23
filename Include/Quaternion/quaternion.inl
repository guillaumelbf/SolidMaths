#include "quaternion.hpp"

#include <cmath>

#define QUATERNION_TEMPLATE template<typename TYPE>
#define QUATERNION sQuaternion<TYPE>

#pragma region Constructor

    QUATERNION_TEMPLATE
    constexpr QUATERNION::sQuaternion() noexcept
    {
        w = 1;
        x = 0;
        y = 0;
        z = 0;
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION::sQuaternion(const sQuaternion& _copy)
    {
        w = _copy.w;
        x = _copy.x;
        y = _copy.y;
        z = _copy.z;
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION::sQuaternion(TYPE _w, TYPE _x, TYPE _y, TYPE _z)
    {
        w = _w;
        x = _x;
        y = _y;
        z = _z;
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION::sQuaternion(TYPE _xAxis, TYPE _yAxis, TYPE _zAxis)
    {
        TYPE cosX = cos(_xAxis*0.5);
        TYPE cosY = cos(_yAxis*0.5);
        TYPE cosZ = cos(_zAxis*0.5);
        TYPE sinX = sin(_xAxis*0.5);
        TYPE sinY = sin(_yAxis*0.5);
        TYPE sinZ = sin(_zAxis*0.5);

        w = cosX * cosY * cosZ - sinX * sinY * sinZ;
        x = sinX * cosY * cosZ + cosX * sinY * sinZ;
        y = cosX * sinY * cosZ - sinX * cosY * sinZ;
        z = cosX * cosY * sinZ + sinX * sinY * cosZ;
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION::sQuaternion(const sVect3<TYPE>& _vect)
    {
        *this = sQuaternion(_vect.x,_vect.y,_vect.z);
    }

#pragma endregion

#pragma region Static Methods

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::lerp(const QUATERNION& _quat1, const QUATERNION& _quat2, float _ratio, bool shortestPath) noexcept
    {
        float cRatio = 1 - _ratio;

        if(shortestPath)
        {
            float sign = (sQuaternion::dot(_quat1, _quat2) < 0.0f) ? -1.0f : 1.0f;

            return sQuaternion(cRatio * _quat1.w + sign * _ratio * _quat2.w,
                               cRatio * _quat1.x + sign * _ratio * _quat2.x,
                               cRatio * _quat1.y + sign * _ratio * _quat2.y,
                               cRatio * _quat1.z + sign * _ratio * _quat2.z);
        }
        else
        {
            return sQuaternion(cRatio * _quat1.w + _ratio * _quat2.w,
                               cRatio * _quat1.x + _ratio * _quat2.x,
                               cRatio * _quat1.y + _ratio * _quat2.y,
                               cRatio * _quat1.z + _ratio * _quat2.z);
        }
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::nlerp(const QUATERNION& _quat1, const QUATERNION& _quat2, float _ratio, bool shortestPath) noexcept
    {
        return lerp(_quat1, _quat2, _ratio, shortestPath).getNormalized();
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::slerp(const QUATERNION& _quat1, const QUATERNION& _quat2, float _ratio, bool shortestPath) noexcept
    {
        float cRatio = 1 - _ratio;
        TYPE dot    = sQuaternion::dot(_quat1,_quat2);
        TYPE theta  = acos(dot);
        TYPE sTheta = sin(theta);

        if(shortestPath)
        {
            float sign = (dot < 0.0f) ? -1.0f : 1.0f;

            return sQuaternion(_quat1 * ((sin(cRatio) * theta) / sTheta) + _quat2 * (sin(sign * _ratio * theta) / sTheta)).getNormalized();
        }
        else
        {
            return sQuaternion(_quat1 * ((sin(cRatio) * theta) / sTheta) + _quat2 * (sin(_ratio * theta) / sTheta)).getNormalized();
        }
    }

    QUATERNION_TEMPLATE
    constexpr TYPE QUATERNION::dot(const QUATERNION& _quat1, const QUATERNION& _quat2) noexcept
    {
        return _quat1.w * _quat2.w + _quat1.x * _quat2.x + _quat1.y * _quat2.y + _quat1.z * _quat2.z;
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getNormalized(const QUATERNION& _quat) noexcept
    {
        TYPE len = _quat.length();
        return sQuaternion(_quat.w / len, _quat.x / len, _quat.y / len, _quat.z / len);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getInverted(const QUATERNION& _quat) noexcept
    {
        return sQuaternion(_quat.w, -_quat.x, -_quat.y, -_quat.z);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getAdded(const QUATERNION& _quat1, const QUATERNION& _quat2) noexcept
    {
        return sQuaternion(_quat1.w + _quat2.w, _quat1.x + _quat2.x, _quat1.y + _quat2.y, _quat1.z + _quat2.z);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getSubstract(const QUATERNION& _quat1, const QUATERNION& _quat2) noexcept
    {
        return sQuaternion(_quat1.w - _quat2.w, _quat1.x - _quat2.x, _quat1.y - _quat2.y, _quat1.z - _quat2.z);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getMultiplied(const QUATERNION& _quat1, const QUATERNION& _quat2) noexcept
    {
        return sQuaternion(_quat1.w * _quat2.w - (_quat1.x * _quat2.x + _quat1.y * _quat2.y + _quat1.z * _quat2.z),
                          _quat1.w * _quat2.x + _quat2.w * _quat1.x + (_quat1.y * _quat2.z - _quat2.y * _quat1.z),
                          _quat1.w * _quat2.y + _quat2.w * _quat1.y + (_quat1.z * _quat2.x - _quat2.z * _quat1.x),
                          _quat1.w * _quat2.z + _quat2.w * _quat1.z + (_quat1.x * _quat2.y - _quat2.x * _quat1.y));
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getMultiplied(const QUATERNION& _quat, TYPE _real) noexcept
    {
        return sQuaternion(_quat.w * _real, _quat.x * _real, _quat.y * _real, _quat.z * _real);
    }

#pragma endregion

#pragma region Methods

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::lerp(const QUATERNION& _quat, float _ratio, bool shortestPath) noexcept
    {
        *this = sQuaternion::lerp(*this,_quat,_ratio,shortestPath);
        return *this;
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::slerp(const QUATERNION& _quat, float _ratio, bool shortestPath) noexcept
    {
        *this = sQuaternion::slerp(*this,_quat,_ratio,shortestPath);
        return *this;
    }

    QUATERNION_TEMPLATE
    constexpr TYPE QUATERNION::dot(const QUATERNION& _quat) const noexcept
    {
        return sQuaternion::dot(*this,_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getNormalized() noexcept
    {
        return sQuaternion::getNormalized(*this);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::normalize() noexcept
    {
        *this = sQuaternion::getNormalized(*this);
        return *this;
    }

    QUATERNION_TEMPLATE
    constexpr TYPE QUATERNION::sqrtLength() const noexcept
    {
        return w * w + x * x + y * y + z * z;
    }

    QUATERNION_TEMPLATE
    constexpr TYPE QUATERNION::length() const noexcept
    {
        return sqrt(sqrtLength());
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getInverted() const noexcept
    {
        return sQuaternion::getInverted(*this);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::invert() noexcept
    {
        *this = sQuaternion::getInverted(*this);
        return *this;
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getAdded(const QUATERNION& _quat) noexcept
    {
        return sQuaternion::getAdded(*this,_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::add(const QUATERNION& _quat) noexcept
    {
        *this = sQuaternion::getAdded(*this,_quat);
        return *this;
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getSubstract(const QUATERNION& _quat) noexcept
    {
        return sQuaternion::getSubstract(*this,_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::substract(const QUATERNION& _quat) noexcept
    {
        *this = sQuaternion::getSubstract(*this,_quat);
        return *this;
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::getMultiplied(const QUATERNION& _quat) const noexcept
    {
        return sQuaternion::getMultiplied(*this,_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::multiply(const QUATERNION& _quat) noexcept
    {
        *this = sQuaternion::getMultiplied(*this,_quat);
        return *this;
    }

#pragma endregion

#pragma region Operator

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::operator=(const QUATERNION& _copy) noexcept
    {
        w = _copy.w;
        x = _copy.x;
        y = _copy.y;
        z = _copy.z;

        return *this;
    }

    QUATERNION_TEMPLATE
    constexpr bool QUATERNION::operator==(const QUATERNION& _quat) noexcept
    {
        return (w == _quat.w && x == _quat.x && y == _quat.y && z == _quat.z);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::operator+(const QUATERNION& _quat) const noexcept
    {
        return sQuaternion::getAdded(*this,_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::operator-(const QUATERNION& _quat) const noexcept
    {
        return sQuaternion::getSubstract(*this,_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::operator*(const QUATERNION& _quat) const noexcept
    {
        return sQuaternion::getMultiplied(*this,_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::operator+=(const QUATERNION& _quat) noexcept
    {
        return this->add(_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::operator-=(const QUATERNION& _quat) noexcept
    {
        return this->substract(_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION& QUATERNION::operator*=(const QUATERNION& _quat) noexcept
    {
        return this->multiply(_quat);
    }

    QUATERNION_TEMPLATE
    constexpr QUATERNION QUATERNION::operator*(Type _real) const noexcept
    {
        return sQuaternion::getMultiplied(*this, _real);
    }

#pragma endregion

#undef QUATERNION_TEMPLATE
#undef QUATERNION