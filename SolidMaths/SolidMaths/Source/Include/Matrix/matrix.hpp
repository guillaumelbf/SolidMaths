#pragma once

#include "baseMatrix.hpp"

template <size_t ROW, size_t COL, typename TYPE = float>
class sMat : public BaseMatrix<ROW,COL,TYPE>
{
public:
    constexpr sMat() {}
    
    constexpr sMat& operator=(const BaseMatrix<ROW,COL,TYPE>& _inMat) noexcept
    {
        *this = static_cast<sMat<ROW,COL,TYPE>>(_inMat);
        return *this;
    }
};