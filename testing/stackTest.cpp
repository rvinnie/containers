#include "stackTest.hpp"

template <typename T>
void			compareValues(T stdValue, T ftValue)
{
	std::cout << "STD:\t" << stdValue << std::endl;
	std::cout << "FT:\t" << ftValue << std::endl << std::endl;
}

void			printHeader(int sizeOfLine, std::string color, std::string name)
{
	//	example: "<<< STRING >>>"
	int countArrows = (sizeOfLine - name.size() - 2) / 2;
	std::cout << color;
	for (int i = 0; i < countArrows; i++)
		std::cout << "<";
	std::cout << " " << name << " ";
	for (int i = 0; i < countArrows; i++)
		std::cout << ">";
	std::cout << RESET << std::endl;
}

template <typename T>
void			integralTest(std::string nameOfTest, size_t sizeOfStack, int seedForRandom)
{
	printHeader(LINE_SIZE, LYELLOW, nameOfTest);
	std::stack<T> stdStack;
	ft::stack<T> ftStack;
	std::cout << YELLOW <<  "1) Empty test" << RESET << std::endl;
	compareValues(stdStack.empty(), ftStack.empty());

	srand(seedForRandom);
	for (size_t i = 0; i < sizeOfStack; i++)
	{
		T value = rand() % 100;
		stdStack.push(value);
		ftStack.push(value);
	}

	compareValues(stdStack.empty(), ftStack.empty());
	std::cout << YELLOW << "2) Size test" << RESET << std::endl;
	compareValues(stdStack.size(), ftStack.size());
	std::cout << YELLOW << "3) Top test" << RESET << std::endl;
	compareValues(stdStack.top(), ftStack.top());
	std::cout << YELLOW << "4) Pop test" << RESET << std::endl;
	stdStack.pop();
	stdStack.pop();
	ftStack.pop();
	ftStack.pop();
	compareValues(stdStack.size(), ftStack.size());
	compareValues(stdStack.top(), ftStack.top());
	std::cout << YELLOW << "5) Push test" << RESET << std::endl;
	stdStack.push(42);
	stdStack.push(77);
	ftStack.push(42);	
	ftStack.push(77);
	compareValues(stdStack.size(), ftStack.size());
	compareValues(stdStack.top(), ftStack.top());
}

void			stringTest()
{
	printHeader(LINE_SIZE, LYELLOW, "STRING");
	std::stack<std::string> stdStack;
	ft::stack<std::string> ftStack;
	std::cout << YELLOW <<  "1) Empty test" << RESET << std::endl;
	compareValues(stdStack.empty(), ftStack.empty());
	stdStack.push("Ben");
	stdStack.push("Bob");
	stdStack.push("Max");
	stdStack.push("John");
	stdStack.push("Diana");
	ftStack.push("Ben");
	ftStack.push("Bob");
	ftStack.push("Max");
	ftStack.push("John");
	ftStack.push("Diana");
	compareValues(stdStack.empty(), ftStack.empty());
	std::cout << YELLOW << "2) Size test" << RESET << std::endl;
	compareValues(stdStack.size(), ftStack.size());
	std::cout << YELLOW << "3) Top test" << RESET << std::endl;
	compareValues(stdStack.top(), ftStack.top());
	std::cout << YELLOW << "4) Pop test" << RESET << std::endl;
	stdStack.pop();
	stdStack.pop();
	ftStack.pop();
	ftStack.pop();
	compareValues(stdStack.size(), ftStack.size());
	compareValues(stdStack.top(), ftStack.top());
	std::cout << YELLOW << "5) Push test" << RESET << std::endl;
	stdStack.push("Mark");
	stdStack.push("Rose");
	ftStack.push("Mark");
	ftStack.push("Rose");
	compareValues(stdStack.size(), ftStack.size());
	compareValues(stdStack.top(), ftStack.top());
}

void			stackTest()
{
	std::cout << LYELLOW << LINE << RESET << std::endl;
	std::cout << LYELLOW << STACK_LINE << RESET << std::endl;
	std::cout << LYELLOW << LINE << RESET << std::endl;

	integralTest<int>("INT", 15, 1);
	integralTest<double>("DOUBLE", 40, 2);
	integralTest<float>("FLOAT", 30, 3);
	integralTest<long>("LONG", 100, 4);
	integralTest<short>("SHORT", 100, 5);
	integralTest<char>("CHAR", 19, 6);
	stringTest();

	std::cout << LYELLOW << LINE << std::endl << LINE << std::endl;
}