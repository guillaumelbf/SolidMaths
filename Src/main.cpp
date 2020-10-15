//TODO: Doxygene every function
//TODO: Matrix
//TODO: Quaternion
#include <iostream>

#include "../Include/Vector/vector.hpp"
#include "../Include/Vector/vector2.hpp"
#include "../Include/Vector/vector3.hpp"
#include "../Include/Vector/vector4.hpp"

int main()
{
	sVect2<> vect2_0(1, 3);
	sVect2<> vect2_1;

	vect2_1 = vect2_0;

	sVect2 normalizedVect;

	normalizedVect = vect2_1.getNormalized();

	std::cout << normalizedVect << std::endl;

	std::cout << vect2_1 << std::endl;

	sVect2<> vect1(1,2);
	sVect4<> vect2(1,2,3,4);

	//sVect2 test = sVect2<>::lerp(vect1, vect2,0.5);

	std::cout << vect2.toString() << std::endl;

    return 0;
}