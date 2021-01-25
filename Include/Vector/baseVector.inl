#include "baseVector.hpp"

#include <string>

#include "../Utils/numerics.hpp"

namespace Solid
{

#define BASE_VECTOR_TEMPLATE template<size_t DIM, typename TYPE>
#define BASE_VECTOR BaseVector<DIM,TYPE>

#pragma region Static Methods

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::lerp(const BASE_VECTOR &_vec1, const BASE_VECTOR &_vec2, float _ratio) noexcept
    {
        return _vec1 + (_vec2 - _vec1) * _ratio;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::slerp(const BASE_VECTOR &_vec1, const BASE_VECTOR &_vec2,
                                             float _ratio) noexcept
    {
        const TYPE dotRes = clamp(dot(_vec1, _vec2), -1.0f, 1.f);
        const TYPE theta = acos(dotRes) * _ratio;

        BaseVector rVect = (_vec2 - _vec1 * dotRes).getNormalized();

        return ((_vec1 * cos(theta)) + rVect * sin(theta));
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::cross(const BASE_VECTOR &_vec1, const BASE_VECTOR &_vec2) noexcept
    {
        return _vec1.cross(_vec2);
    }

    BASE_VECTOR_TEMPLATE
    constexpr TYPE BASE_VECTOR::dot(const BASE_VECTOR &_vec1, const BASE_VECTOR &_vec2) noexcept
    {
        return _vec1.dot(_vec2);
    }

#pragma endregion

#pragma region Methods

    BASE_VECTOR_TEMPLATE
    constexpr TYPE BASE_VECTOR::sqrtLength() const noexcept
    {
        TYPE result{};

        for (size_t i = 0; i < DIM; i++)
            result += this->data[i] * this->data[i];

        return result;
    }

    BASE_VECTOR_TEMPLATE
    constexpr TYPE BASE_VECTOR::length() const noexcept
    {
        return sqrt(sqrtLength());
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::normalize() noexcept
    {
        TYPE len = length();

        if (len != 0)
        {
            for (size_t i = 0; i < DIM; i++)
                this->data[i] /= len;
        }

        return *this;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::getNormalized() const noexcept
    {
        return BASE_VECTOR(*this).normalize();
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::add(const BASE_VECTOR &_vec) noexcept
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] += _vec[i];

        return *this;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::subtract(const BASE_VECTOR &_vec) noexcept
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] -= _vec[i];

        return *this;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::multiply(const BASE_VECTOR &_vec) noexcept
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] *= _vec[i];

        return *this;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::divide(const BASE_VECTOR &_vec) noexcept
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] = (_vec[i] != 0) ? this->data[i] / _vec[i] : 0;

        return *this;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::add(const Type &_value) noexcept
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] += _value;

        return *this;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::subtract(const Type &_value) noexcept
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] -= _value;

        return *this;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::multiply(const Type &_value) noexcept
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] *= _value;

        return *this;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::divide(const Type &_value) noexcept
    {
        if (_value == 0)
            return *this;

        for (size_t i = 0; i < DIM; i++)
            this->data[i] /= _value;

        return *this;
    }

    BASE_VECTOR_TEMPLATE
    constexpr bool BASE_VECTOR::isEquals(const BASE_VECTOR &_vec) const noexcept
    {
        for (size_t i = 0; i < DIM; i++)
        {
            if (this->data[i] != _vec[i])
                return false;
        }

        return true;
    }

    BASE_VECTOR_TEMPLATE
    constexpr TYPE BASE_VECTOR::dot(const BASE_VECTOR &_vec) const noexcept
    {
        TYPE result{};

        for (size_t i = 0; i < DIM; i++)
            result += this->data[i] * _vec[i];

        return result;
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::cross(const BASE_VECTOR &_vec) const noexcept
    {
        BaseVector result;

        for (size_t i = 0; i < DIM; i++)
            result.data[i] =
                    this->data[(i + 1) % DIM] * _vec[(i + 2) % DIM] - _vec[(i + 1) % DIM] * _vec[(i + 2) % DIM];

        return result;
    }

    BASE_VECTOR_TEMPLATE
    std::string BASE_VECTOR::toString() const noexcept
    {
        std::string result;
        for (size_t i = 0; i < DIM; i++)
        {
            result += std::to_string(i) + ':';
            result += std::to_string(data.at(i));
            if (i != DIM - 1)
            { result += ','; }
        }

        return result;
    }

#pragma endregion

#pragma region Operator

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::operator+(const BASE_VECTOR &_vec) const noexcept
    {
        return BASE_VECTOR(*this).add(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::operator-(const BASE_VECTOR &_vec) const noexcept
    {
        return BASE_VECTOR(*this).subtract(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::operator*(const BASE_VECTOR &_vec) const noexcept
    {
        return BASE_VECTOR(*this).multiply(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::operator/(const BASE_VECTOR &_vec) const noexcept
    {
        return BASE_VECTOR(*this).divide(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::operator+=(const BASE_VECTOR &_vec) noexcept
    {
        return add(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::operator-=(const BASE_VECTOR &_vec) noexcept
    {
        return subtract(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::operator*=(const BASE_VECTOR &_vec) noexcept
    {
        return multiply(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::operator/=(const BASE_VECTOR &_vec) noexcept
    {
        return divide(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::operator+(const Type &_value) const noexcept
    {
        return BASE_VECTOR(*this).add(_value);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::operator-(const Type &_value) const noexcept
    {
        return BASE_VECTOR(*this).subtract(_value);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::operator*(const Type &_value) const noexcept
    {
        return BASE_VECTOR(*this).multiply(_value);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR BASE_VECTOR::operator/(const Type &_value) const noexcept
    {
        return BASE_VECTOR(*this).divide(_value);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::operator+=(const Type &_value) noexcept
    {
        return add(_value);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::operator-=(const Type &_value) noexcept
    {
        return subtract(_value);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::operator*=(const Type &_value) noexcept
    {
        return multiply(_value);
    }

    BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR &BASE_VECTOR::operator/=(const Type &_value) noexcept
    {
        return divide(_value);
    }

    /*BASE_VECTOR_TEMPLATE
    constexpr BASE_VECTOR& BASE_VECTOR::operator=(const BASE_VECTOR& _vec) noexcept
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] = _vec[i];

        return *this;
    }*/

    BASE_VECTOR_TEMPLATE
    constexpr bool BASE_VECTOR::operator==(const SelfType &_vec) const noexcept
    {
        return isEquals(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr bool BASE_VECTOR::operator!=(const SelfType &_vec) const noexcept
    {
        return !isEquals(_vec);
    }

    BASE_VECTOR_TEMPLATE
    constexpr TYPE BASE_VECTOR::operator[](const size_t _index) const noexcept
    {
        return this->data[_index];
    }

    BASE_VECTOR_TEMPLATE
    constexpr TYPE &BASE_VECTOR::operator[](const size_t _index) noexcept
    {
        return this->data[_index];
    }

#pragma endregion

#undef BASE_VECTOR_TEMPLATE
#undef BASE_VECTOR

} //!namespace