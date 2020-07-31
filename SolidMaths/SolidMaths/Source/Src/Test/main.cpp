#include <iostream>

#include "../../Include/Vector/vector2.hpp"
#include "../../Include/Vector/vector.hpp"

#include "../../Include/Matrix/matrix.hpp"

int main()
{
	sVect2<> vect2_0(1, 3);
	sVect2<> vect2_1;

	vect2_1 = vect2_0;

	std::cout << vect2_0.x << "," << vect2_0.y << std::endl;
	std::cout << vect2_1.x << "," << vect2_1.y << std::endl;
	vect2_1.x = 5;
	std::cout << vect2_0.x << "," << vect2_0.y << std::endl;
	std::cout << vect2_1.x << "," << vect2_1.y << std::endl;

	sMat<1, 3> mat;
	sMat<3, 1> mat2;
	sMat<1, 1> mat3;

	mat.at(0, 0) = 1;
	mat.at(0, 1) = 2;
	mat.at(0, 2) = 3;

	mat.transpose(mat2);
	mat.multiply(mat2,mat3);

	std::cout << mat << std::endl;
	std::cout << mat2 << std::endl;
	std::cout << mat3 << std::endl;


	return 0;
}