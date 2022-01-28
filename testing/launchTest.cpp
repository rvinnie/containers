#include "launchTest.hpp"

void printGreeting()
{
	std::cout << "greeting" << std::endl;
 // all
 // vector
 // stack
 // map
 // set
}

int	getTestNumber(std::string value)
{
	int testNumber;

	if (value == "all")
		testNumber = 1;
	else if (value == "vector")
		testNumber = 2;
	else if (value == "stack")
		testNumber = 3;
	else if (value == "map")
		testNumber = 4;
	else if (value == "set")
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
		case 2:
			vectorTest();
			break;
		case 3:
			stackTest();
			break;
		case 4:
			mapTest();
			break;
		case 5:
			setTest();
			break;
		default:
			vectorTest();
			getchar();
			stackTest();
			getchar();
			mapTest();
			getchar();
			setTest();
			getchar();
	}
	return 0;
}