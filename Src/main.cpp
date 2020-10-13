#include <iostream>

#include "../Include/Vector/vector.hpp"
#include "../Include/Vector/vector2.hpp"

int main()
{
	sVect2<> vect2_0(1, 3);
	sVect2<> vect2_1;

	vect2_1 = vect2_0;

	sVect2 normalizedVect;

	normalizedVect = vect2_1.normalize();

	std::cout << normalizedVect.x << "," << normalizedVect.y << std::endl;

	std::cout << vect2_1.x << "," << vect2_1.y << std::endl;

	return 0;
}