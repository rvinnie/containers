#include "launchTest.hpp"
#include "../stack/stack.hpp"

// using ft::stack;

// template <typename T>
// std::stack<T>	getRandomStdStack(size_t count, int seed = 555)
// {
// 	srand(seed);
// 	std::stack<T> stack;
// 	for (size_t i = 0; i < count; i++)
// 		stack.push((T)(rand() % 100));
// 	return stack;
// }

// template <typename T>
// ft::stack<T>	getRandomFtStack(size_t count, int seed = 555)
// {
// 	srand(seed);
// 	ft::stack<T> stack;
// 	for (size_t i = 0; i < count; i++)
// 		stack.push((T)(rand() % 100));
// 	return stack;
// }

template <typename T>
void			compareValues(T stdValue, T ftValue)
{
	std::cout << "STD:\t" << stdValue << std::endl;
	std::cout << "FT:\t" << ftValue << std::endl << std::endl;
}

std::string		getColor(int seed)
{
	(void)seed;
	std::string color;
	// std::stringstream ss;
	// ss << seed;
	color = "\x1b[1;33;42m";
	return color;
}

template <typename T>
void			integralTest(std::string name, size_t size, int seed) // does not accept strings
{
	std::cout << getColor(seed) << "<<<< " << name << " >>>>" << COLOR_RESET << std::endl;
	std::stack<T> stdStack;
	ft::stack<T> ftStack;
	std::cout << "1) Empty test" << std::endl;
	compareValues(stdStack.empty(), ftStack.empty());

	srand(seed);
	for (size_t i = 0; i < size; i++)
	{
		T value = rand() % 100;
		stdStack.push(value);
		ftStack.push(value);
	}

	compareValues(stdStack.empty(), ftStack.empty());
	std::cout << "2) Size test" << std::endl;
	compareValues(stdStack.size(), ftStack.size());
	std::cout << "3) Top test" << std::endl;
	compareValues(stdStack.top(), ftStack.top());
	std::cout << "4) Pop test" << std::endl;
	stdStack.pop();
	stdStack.pop();
	ftStack.pop();
	ftStack.pop();
	compareValues(stdStack.size(), ftStack.size());
	compareValues(stdStack.top(), ftStack.top());
	std::cout << "5) Push test" << std::endl;
	stdStack.push(42);
	stdStack.push(77);
	ftStack.push(42);	
	ftStack.push(77);
	compareValues(stdStack.size(), ftStack.size());
	compareValues(stdStack.top(), ftStack.top());
}

void			stringTest()
{
	std::cout << COLOR_RED << "< STRING >" << COLOR_RESET << std::endl;
	std::stack<std::string> stdStack;
	ft::stack<std::string> ftStack;

	std::cout << "1) Empty test" << std::endl;
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
	std::cout << "2) Size test" << std::endl;
	compareValues(stdStack.size(), ftStack.size());
	std::cout << "3) Top test" << std::endl;
	compareValues(stdStack.top(), ftStack.top());
	std::cout << "4) Pop test" << std::endl;
	stdStack.pop();
	stdStack.pop();
	ftStack.pop();
	ftStack.pop();
	compareValues(stdStack.size(), ftStack.size());
	compareValues(stdStack.top(), ftStack.top());
	std::cout << "5) Push test" << std::endl;
	stdStack.push("Mark");
	stdStack.push("Rose");
	ftStack.push("Mark");
	ftStack.push("Rose");
	compareValues(stdStack.size(), ftStack.size());
	compareValues(stdStack.top(), ftStack.top());
}

void			stackTest()
{
	std::cout << COLOR_GREEN << "/////// STACK TESTS ///////" << COLOR_RESET << std::endl;
	integralTest<int>("INT", 15, 1);
	integralTest<double>("DOUBLE", 40, 2);
	integralTest<float>("FLOAT", 30, 3);
	integralTest<long>("LONG", 100, 4);
	integralTest<short>("SHORT", 100, 5);
	integralTest<char>("CHAR", 19, 6);
	stringTest();
}