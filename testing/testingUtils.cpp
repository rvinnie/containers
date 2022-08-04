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