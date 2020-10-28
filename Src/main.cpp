//TODO: Doxygene every function
//TODO: Matrix
//TODO: Quaternion
#include <iostream>

#include "../Include/Matrix/matrix.hpp"
#include "../Include/Matrix/matrix3.hpp"
#include "../Include/Matrix/matrix4.hpp"

int main()
{
	sMat<2,3> mat;

	mat.at(0,0) = 1;
    mat.at(0,1) = 2;
    mat.at(0,2) = 3;
    mat.at(1,0) = 4;
    mat.at(1,1) = 5;
    mat.at(1,2) = 6;

    sMat<3,2> mat2 = sMat<2,3>::getTransposed(mat);

    std::cout << mat << std::endl;
    std::cout << mat2 << std::endl;

    sMat<2,2> mat3 = sMat<2,3>::getMultiplied<3,2>(mat,mat2);

    std::cout << mat3 << std::endl;

    //sSquareMat<4> mat4 = sSquareMat<4>::identity();
    sMat3<> mat4;

    mat4 = sMat3<>::identity();

    std::cout << mat4 << std::endl;

    sMat4 mat5(1);

    mat5.at(5) = 42;

    std::cout << mat5 << std::endl;

    return 0;
}