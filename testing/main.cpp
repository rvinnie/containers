#include "main.hpp"

void printGreeting()
{
	std::cout << "./test [all | vector | stack | map | set]" << std::endl;
}

int	getTestNumber(std::string value)
{
	int testNumber;

	if (value == "vector")
		testNumber = 1;
	else if (value == "stack")
		testNumber = 2;
	else if (value == "map")
		testNumber = 3;
	else if (value == "set")
		testNumber = 4;
	else if (value == "all")
		testNumber = 5;
	else
		testNumber = -1;
	return testNumber;
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printGreeting();
		return 1;
	}

	int testNumber = getTestNumber(std::string(argv[1]));
	if (testNumber == -1)
	{
		printGreeting();
		return 2;
	}

	switch (testNumber)
	{
		case 1:
			vectorTest();
			break;
		case 2:
			stackTest();
			break;
		case 3:
			mapTest();
			break;
		case 4:
			setTest();
			break;
		case 5:
			vectorTest();
			getchar();
			stackTest();
			getchar();
			mapTest();
			getchar();
			setTest();
	}
	return 0;
}