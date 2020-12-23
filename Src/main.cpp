//TODO: Doxygene every function
//TODO: Verify Matrix
#include <iostream>

#include <array>

#include "Vector/vector4.hpp"
#include "Matrix/matrix.hpp"
#include "Matrix/matrix3.hpp"
#include "Matrix/matrix4.hpp"
#include "Matrix/squareMatrix.hpp"
#include "Quaternion/quaternion.hpp"

void vectorTest()
{

}

void matrixTest()
{
    sMat<2,3,float> mat(std::array{1.f,2.f,3.f,4.f,5.f,6.f});

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

    sMat<2,3> add(std::array{1.f,2.f,3.f,4.f,5.f,6.f});

    std::cout << sMat<2,3>::getAdd(add,add) << std::endl;

    sMat<2,3> sub1(std::array{1.f,2.f,3.f,4.f,5.f,6.f});
    sMat<2,3> sub2(std::array{6.f,5.f,4.f,3.f,2.f,1.f});

    std::cout << sMat<2,3>::getSubtract(sub1,sub2) << std::endl;
}

void squareMatrixTest()
{
    sSquareMat<3> mat;

    for (int i = 0; i < mat.getNbElements(); ++i)
        mat.at(i) = i+1;

    sSquareMat<3> mat2 = mat;
    sSquareMat<3> mat3;
    for (int i = 0; i < mat.getNbElements(); ++i)
        mat3.at(i) = mat.at((mat.getNbElements()-i)-1);

    sMat4 mat4;
    for (int i = 0; i < mat4.getNbElements(); ++i)
        mat4.at(i) = i+1;
    sVect4 vect4;
    for (int i = 0; i < 4; ++i)
        vect4[i] = i+1;

    std::cout << mat << std::endl;
    std::cout << mat3 << std::endl;

    std::cout << sSquareMat<3>::getMultiplied(mat,mat3) << std::endl;

    mat.transpose();

    std::cout << mat << std::endl;

    mat2.at(4) = 0;

    std::cout << mat2.getInverted() << std::endl;

    std::cout << "Mat4: \n" << mat4 << std::endl;
    std::cout << "Vect4: \n" << vect4 << std::endl;

    std::cout << "Mat4 * Vect4: \n" << sMat4<>::getMultiplied(mat4,vect4) << std::endl;
}

void quaternionTest()
{
    sQuaternion quat(1.f,0.1f,0.2f,0.3f);
    sQuaternion quat2(1.f,0.4f,0.4f,0.4f);

    std::cout << quat << std::endl;

    quat.lerp(quat2,0.5f);

    std::cout << quat << std::endl;
}

int main()
{

    matrixTest();
    //squareMatrixTest();
    //quaternionTest();

    return 0;
}