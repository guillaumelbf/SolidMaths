#include <iostream>

#include "../../Include/Vector/vector2.hpp"
#include "../../Include/Vector/vector.hpp"

int main()
{
	sVect2<> vect(1,3);
	sVect2<> vect2(1, 1);

	sVect<5> vect5;

	std::cout << vect.x << "," << vect.y << std::endl;
	std::cout << vect5[0] << "," << vect5[4] << std::endl;

	return 0;
}