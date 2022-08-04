#include "main.hpp"

void	stackTest()
{
	std::stack<int> stdStack;
	ft::stack<int> ftStack;
	std::stack<std::string> stdStrStack;
	ft::stack<std::string> ftStrStack;

	const size_t sizeOfStack = 15;
	const size_t randomSeed = 17;
	srand(randomSeed);

	std::cout << LYELLOW << LINE << RESET << std::endl;
	std::cout << LYELLOW << STACK_LINE << RESET << std::endl;
	std::cout << LYELLOW << LINE << RESET << std::endl;

	compareValues("is stack empty (before pushing)", ftStack.empty(), stdStack.empty());
	for (size_t i = 0; i < sizeOfStack; i++)
	{
		int value = rand() % 100;
		stdStack.push(value);
		ftStack.push(value);
	}
	compareValues("is stack empty (after pushing)", ftStack.empty(), stdStack.empty());

	compareValues("stack size", ftStack.size(), stdStack.size());
	stdStack.push(33);
	ftStack.push(33);
	compareValues("stack size", ftStack.size(), stdStack.size());

	stdStack.pop();
	stdStack.pop();
	ftStack.pop();
	ftStack.pop();
	compareValues("stack after pop", stdStack.size(), ftStack.size());
	compareValues("stack after pop", stdStack.top(), ftStack.top());

	stdStack.push(42);
	stdStack.push(77);
	ftStack.push(42);	
	ftStack.push(77);
	compareValues("stack after push", stdStack.size(), ftStack.size());
	compareValues("stack after push", stdStack.top(), ftStack.top());

	stdStrStack.push("Ben");
	stdStrStack.push("Bob");
	stdStrStack.push("Max");
	stdStrStack.push("Diana");
	stdStrStack.push("John");
	ftStrStack.push("Ben");
	ftStrStack.push("Bob");
	ftStrStack.push("Max");
	ftStrStack.push("Diana");
	ftStrStack.push("John");
	compareValues("stack top", ftStack.top(), stdStack.top());
	compareValues("stack top", ftStrStack.top(), stdStrStack.top());
	std::cout << LYELLOW << LINE << std::endl << LINE << std::endl;
}