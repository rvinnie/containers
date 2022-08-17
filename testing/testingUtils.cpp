#include "main.hpp"

void    printHeader(int sizeOfLine, std::string color, std::string name)
{
	int countArrows = (sizeOfLine - name.size() - 2) / 2;
	std::cout << color;
	for (int i = 0; i < countArrows; i++)
		std::cout << "<";
	std::cout << " " << name << " ";
	for (int i = 0; i < countArrows; i++)
		std::cout << ">";
	std::cout << RESET << std::endl << std::endl;
}

double	difftime_in_ms(unsigned int start_time, unsigned int end_time)
{
	return 1000.0 * (end_time - start_time) / CLOCKS_PER_SEC;
}