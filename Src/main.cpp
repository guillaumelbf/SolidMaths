//TODO: Doxygene every function
//TODO: Verify Matrix
#include <iostream>

#include <array>

#include "Vector/vector4.hpp"
#include "Vector/vector3.hpp"
#include "Vector/vector.hpp"
#include "Matrix/matrix.hpp"
#include "Matrix/matrix3.hpp"
#include "Matrix/matrix4.hpp"
#include "Matrix/squareMatrix.hpp"
#include "Quaternion/quaternion.hpp"

using namespace Solid;

void vectorTest()
{
    Vec<4> vec(5);
    Vec<4> vec2;

    vec2 = vec;
    vec2[0] = 8;

    std::cout << vec << std::endl;
    std::cout << vec2 << std::endl;

    Vec3 vect_3;

    vect_3.x = 5;

    Vec3 vect2_3;

    vect2_3 = vect_3;
    vect2_3.z = 8;

    std::cout << vect2_3 << std::endl;

    Vec3 vect3_3(vect2_3);

    vect3_3.z = 5;

    std::cout << vect2_3 << std::endl;
    std::cout << vect3_3 << std::endl;

}

void matrixTest()
{
    Mat<2,3,float> mat(std::array{1.f, 2.f, 3.f, 4.f, 5.f, 6.f});

    Mat<3,2> mat2 = Mat<2,3>::getTransposed(mat);

    std::cout << mat << std::endl;
    std::cout << mat2 << std::endl;

    Mat<2,2> mat3 = Mat<2,3>::getMultiplied<3,2>(mat, mat2);

    std::cout << mat3 << std::endl;

    //sSquareMat<4> mat4 = sSquareMat<4>::identity();
    Mat3<> mat4;

    mat4 = Mat3<>::identity();

    std::cout << mat4 << std::endl;

    Mat4 mat5(1);

    mat5.at(5) = 42;

    std::cout << mat5 << std::endl;

    Mat<2,3> add(std::array{1.f, 2.f, 3.f, 4.f, 5.f, 6.f});

    std::cout << Mat<2,3>::getAdd(add, add) << std::endl;

    Mat<2,3> sub1(std::array{1.f, 2.f, 3.f, 4.f, 5.f, 6.f});
    Mat<2,3> sub2(std::array{6.f, 5.f, 4.f, 3.f, 2.f, 1.f});

    std::cout << Mat<2,3>::getSubtract(sub1, sub2) << std::endl;

    std::cout << mat.toString() << std::endl;
}

void squareMatrixTest()
{
    SquareMat<3> mat;

    for (int i = 0; i < mat.getNbElements(); ++i)
        mat.at(i) = i+1;

    SquareMat<3> mat2 = mat;
    SquareMat<3> mat3;
    for (int i = 0; i < mat.getNbElements(); ++i)
        mat3.at(i) = mat.at((mat.getNbElements()-i)-1);

    Mat4 mat4;
    for (int i = 0; i < mat4.getNbElements(); ++i)
        mat4.at(i) = i+1;
    Vec4 vec4;
    for (int i = 0; i < 4; ++i)
        vec4[i] = i+1;

    std::cout << mat << std::endl;
    std::cout << mat3 << std::endl;

    std::cout << SquareMat<3>::getMultiplied(mat, mat3) << std::endl;

    mat.transpose();

    std::cout << mat << std::endl;

    mat2.at(4) = 0;

    std::cout << mat2.getInverted() << std::endl;

    std::cout << "Mat4: \n" << mat4 << std::endl;
    std::cout << "Vect4: \n" << vec4 << std::endl;

    std::cout << "Mat4 * Vect4: \n" << Mat4<>::getMultiplied(mat4, vec4) << std::endl;
}

void quaternionTest()
{
    Quat quat(1.f, 0.1f, 0.2f, 0.3f);
    Quat quat2(1.f, 0.4f, 0.4f, 0.4f);

    std::cout << quat << std::endl;

    quat.lerp(quat2,0.5f);

    std::cout << quat << std::endl;
}

void angleTest()
{

}

int main()
{
    vectorTest();
    //matrixTest();
    //squareMatrixTest();
    //quaternionTest();
    //angleTest();

    return 0;
}