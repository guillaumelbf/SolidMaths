#include "vector.hpp"

namespace Solid
{

#define VECTOR_TEMPLATE template<size_t DIM, typename TYPE>
#define VECTOR Vec<DIM,TYPE>

    VECTOR_TEMPLATE
    constexpr VECTOR::Vec(const TYPE &_value)
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] = _value;
    }

    VECTOR_TEMPLATE
    constexpr VECTOR::Vec(const BaseVector <DIM, TYPE> &_copy)
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] = _copy[i];
    }

    VECTOR_TEMPLATE
    constexpr VECTOR &VECTOR::operator=(const BaseVector <DIM, TYPE> &_copy) noexcept
    {
        for (size_t i = 0; i < DIM; i++)
            this->data[i] = _copy[i];

        return *this;
    }

#undef VECTOR_TEMPLATE
#undef VECTOR

} //!namespace