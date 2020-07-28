#pragma once

#include "baseMatrix.hpp"

template <size_t ROW, size_t COL, typename TYPE = float>
class sMat : public BaseMatrix<sMat<ROW,COL,TYPE>,ROW,COL,TYPE>
{
public:


};