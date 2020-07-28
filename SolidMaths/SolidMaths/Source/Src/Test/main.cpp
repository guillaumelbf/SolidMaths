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



	return 0;
}