#include "vectorTest.hpp"

// std::vector<int>	getRandomVector(size_t count, int seed = 555)
// {
// 	srand(seed);
// 	std::vector<int> vect;
// 	for (size_t i = 0; i < count; i++)
// 		vect.push_back(rand() % 100);
// 	return vect;
// }

// template <typename T>
// void			printStdVector(std::vector<T> vect)
// {
// 	std::cout << "[ ";
// 	for (size_t i = 0; i < vect.size(); i++)
// 		std::cout << vect[i] << " "; 
// 	std::cout << "]" << std::endl;	
// }


void vectorTest()
{
	std::cout << LMAGENTA << LINE << RESET << std::endl;
	std::cout << LMAGENTA << VECTOR_LINE << RESET << std::endl;
	std::cout << LMAGENTA << LINE << RESET << std::endl;

	std::vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << ") " << "size: " << v.size() << " capacity: " << v.capacity()  << std::endl;
		v.push_back(i);
	}

	std::cout << LMAGENTA << LINE << std::endl << LINE << std::endl;
}