#include "baseVector.hpp"

#define BASE_VECTOR_TEMPLATE template<class CHILD, size_t DIM, typename TYPE> 
#define BASE_VECTOR BaseVector<CHILD,DIM,TYPE>

#pragma region Static Methods
	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::lerp(const BASE_VECTOR& _vect1, const BASE_VECTOR& _vect2, float _ratio) noexcept
	{
		return _vect1 + _ratio * (_vect2 - _vect1);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::cross(const BASE_VECTOR& _vect1, const BASE_VECTOR& _vect2) noexcept
	{
		return _vect1.cross(_vect2);
	}

	BASE_VECTOR_TEMPLATE
	constexpr TYPE BASE_VECTOR::dot(const BASE_VECTOR& _vect1, const BASE_VECTOR& _vect2) noexcept
	{
		return _vect1.dot(_vect2);
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
	constexpr BASE_VECTOR& BASE_VECTOR::normalize() noexcept
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
	constexpr BASE_VECTOR& BASE_VECTOR::add(const BASE_VECTOR& _vect) noexcept
	{
		for (size_t i = 0; i < DIM; i++)
			this->data[i] += _vect[i];

		return *this;
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::subtract(const BASE_VECTOR& _vect) noexcept
	{
		for (size_t i = 0; i < DIM; i++)
			this->data[i] -= _vect[i];

		return *this;
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::multiply(const BASE_VECTOR& _vect) noexcept
	{
		for (size_t i = 0; i < DIM; i++)
			this->data[i] -= _vect[i];

		return *this;
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::divide(const BASE_VECTOR& _vect) noexcept
	{
		for (size_t i = 0; i < DIM; i++)
			this->data[i] = (_vect[i] != 0) ? this->data[i] / _vect[i] : 0;

		return *this;
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::add(const Type& _value) noexcept
	{
		for (size_t i = 0; i < DIM; i++)
			this->data[i] += _value;

		return *this;
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::subtract(const Type& _value) noexcept
	{
		for (size_t i = 0; i < DIM; i++)
			this->data[i] -= _value;

		return *this;
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::multiply(const Type& _value) noexcept
	{
		for (size_t i = 0; i < DIM; i++)
			this->data[i] *= _value;

		return *this;
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::divide(const Type& _value) noexcept
	{
		if (_value == 0)
			return *this;

		for (size_t i = 0; i < DIM; i++)
			this->data[i] /= _value;

		return *this;
	}

	BASE_VECTOR_TEMPLATE
	constexpr bool BASE_VECTOR::isEquals(const BASE_VECTOR& _vect) const noexcept
	{
		for (size_t i = 0; i < DIM; i++)
		{
			if (this->data[i] != _vect[i])
				return false;
		}

		return true;
	}

	BASE_VECTOR_TEMPLATE
	constexpr TYPE BASE_VECTOR::dot(const BASE_VECTOR& _vect) const noexcept
	{
		TYPE result{};

		for (size_t i = 0; i < DIM; i++)
			result += this->data[i] * _vect[i];

		return result;
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::cross(const BASE_VECTOR& _vect) const noexcept
	{
		BaseVector result;

		for (size_t i = 0; i < DIM; i++)
			result.data[i] = this->data[(i + 1) % DIM] * _vect[(i + 2) % DIM] - _vect[(i + 1) % DIM] * _vect[(i + 2) % DIM];

		return result;
	}
#pragma endregion

#pragma region Operator

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::operator+(const BASE_VECTOR& _vect) const noexcept
	{
		return BASE_VECTOR(*this).add(_vect);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::operator-(const BASE_VECTOR& _vect) const noexcept
	{
		return BASE_VECTOR(*this).subtract(_vect);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::operator*(const BASE_VECTOR& _vect) const noexcept
	{
		return BASE_VECTOR(*this).multiply(_vect);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::operator/(const BASE_VECTOR& _vect) const noexcept
	{
		return BASE_VECTOR(*this).divide(_vect);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::operator+=(const BASE_VECTOR& _vect) noexcept
	{
		return add(_vect);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::operator-=(const BASE_VECTOR& _vect) noexcept
	{
		return subtract(_vect);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::operator*=(const BASE_VECTOR& _vect) noexcept
	{
		return multiply(_vect);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::operator/=(const BASE_VECTOR& _vect) noexcept
	{
		return divide(_vect);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::operator+(const Type& _value) const noexcept
	{
		return BASE_VECTOR(*this).add(_value);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::operator-(const Type& _value) const noexcept
	{
		return BASE_VECTOR(*this).subtract(_value);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::operator*(const Type& _value) const noexcept
	{
		return BASE_VECTOR(*this).multiply(_value);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR BASE_VECTOR::operator/(const Type& _value) const noexcept
	{
		return BASE_VECTOR(*this).divide(_value);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::operator+=(const Type& _value) noexcept
	{
		return add(_value);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::operator-=(const Type& _value) noexcept
	{
		return subtract(_value);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::operator*=(const Type& _value) noexcept
	{
		return multiply(_value);
	}

	BASE_VECTOR_TEMPLATE
	constexpr BASE_VECTOR& BASE_VECTOR::operator/=(const Type& _value) noexcept
	{
		return divide(_value);
	}

	BASE_VECTOR_TEMPLATE
	constexpr TYPE BASE_VECTOR::operator[](const size_t _index) const noexcept
	{
		return this->data[_index];
	}

	BASE_VECTOR_TEMPLATE
	constexpr TYPE& BASE_VECTOR::operator[](const size_t _index) noexcept
	{
		return this->data[_index];
	}
#pragma endregion

#undef BASE_VECTOR_TEMPLATE
#undef BASE_VECTOR