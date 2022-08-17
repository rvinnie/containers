#include "main.hpp"

void testVectorIterator() 
{
	int val;
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

	std::cout << GREEN << "Vector elem: " << RESET;
	for (int i = 0; i < 10; i++)
	{
		val = rand() % 10;
		ft_vec.push_back(val);
		std_vec.push_back(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	compareVectorValues("iterator", ft_vec.begin(), ft_vec.end(), std_vec.begin(), std_vec.end());
	compareVectorValues("reverse iterator", ft_vec.rbegin(), ft_vec.rend(), std_vec.rbegin(), std_vec.rend());
}

void testVectorModifiers() 
{
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

	ft_vec.assign(5,5);
	std_vec.assign(5,5);
	compareVectorValues("vector after assign", ft_vec, std_vec);

	int val;
	ft::vector<int> ft_buf_vec;
	std::vector<int> std_buf_vec;

	std::cout << GREEN << "Vector elem: " << RESET;
	for (int i = 0; i < 10; i++) {
		val = rand() % 10;
		ft_buf_vec.push_back(val);
		std_buf_vec.push_back(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	ft::vector<int>::iterator ft_it = ft_buf_vec.begin();
	ft::vector<int>::iterator ft_ite = ft_buf_vec.end();
	ft_vec.assign(ft_it,ft_ite);

	std::vector<int>::iterator std_it = std_buf_vec.begin();
	std::vector<int>::iterator std_ite = std_buf_vec.end();
	std_vec.assign(std_it, std_ite);
	compareVectorValues("vector after assign", ft_vec, std_vec);

	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	ft_vec.pop_back();
	std_vec.pop_back();
	std_vec.pop_back();
	std_vec.pop_back();
	std_vec.pop_back();
	compareVectorValues("vector after pop back", ft_vec, std_vec);

	ft_vec.insert(ft_vec.end(), 777);
	std_vec.insert(std_vec.end(), 777);

	ft_vec.insert(ft_vec.begin(), 5, 777);
	std_vec.insert(std_vec.begin(), 5, 777);
	compareVectorValues("vector after insert", ft_vec, std_vec);

	ft_vec.insert(ft_vec.begin(), ft_it, ft_ite);
	std_vec.insert(std_vec.begin(), std_it, std_ite);
	compareVectorValues("vector after insert", ft_vec, std_vec);

	ft_vec.erase(ft_vec.end() - 1);
  	ft_vec.erase(ft_vec.begin(), ft_vec.begin() + 3);
	std_vec.erase(std_vec.end() - 1);
	std_vec.erase(std_vec.begin(), std_vec.begin() + 3);
	compareVectorValues("vector after erase", ft_vec, std_vec);

	ft::vector<int> ft_swap_vec;
	std::vector<int> std_swap_vec;

	for (int i = 0; i < 10; i++)
	{
		val = rand() & 10;
		ft_swap_vec.push_back(val + 5);
		std_swap_vec.push_back(val + 10);
	}
	std::cout << std::endl;

	compareVectorValues("vector before swap", ft_swap_vec, std_swap_vec);
	ft_vec.swap(ft_swap_vec);
	std_vec.swap(std_swap_vec);
	compareVectorValues("vector after swap", ft_swap_vec, std_swap_vec);

	ft_vec.clear();
	std_vec.clear();
	compareVectorValues("vector after clear", ft_vec, std_vec);
	compareValues("is vector empty", ft_vec.empty(), std_vec.empty());	
}

void testVectorCapacity() 
{
	ft::vector<int> ft_vec(10, 5);
	std::vector<int> std_vec(10, 5);

	ft::vector<int> ft_empty_vec;
	std::vector<int> std_empty_vec;
	compareValues("vector size", ft_vec.size(), std_vec.size());

	ft_vec.push_back(10);
	std_vec.push_back(10);
	ft_vec.push_back(20);
	std_vec.push_back(20);
	compareValues("vector size", ft_vec.size(), std_vec.size());

	ft_vec.pop_back();
	std_vec.pop_back();
	compareValues("vector size", ft_vec.size(), std_vec.size());

	ft_vec.resize(5);
	std_vec.resize(5);
	compareValues("vector after resize", ft_vec.size(), std_vec.size());
	compareValues("vector capacity", ft_vec.capacity(), std_vec.capacity());

	compareValues("is vector empty", ft_vec.empty(), std_vec.empty());
	compareValues("is vector empty", ft_empty_vec.empty(), ft_empty_vec.empty());
	
	ft_vec.reserve(100);
	std_vec.reserve(100);
	compareValues("vector capacity after reserve", ft_vec.empty(), std_vec.empty());
	compareValues("vector max size", ft_vec.max_size(), std_vec.max_size());
}

void testVectorElementAccess() 
{
	int val;
	ft::vector<int> ft_vec;
	std::vector<int> std_vec;

	std::cout << GREEN << "Vector elem: " << RESET;
	for (int i = 0; i < 10; i++)
	{
		val = rand() % 10;
		ft_vec.push_back(val);
		std_vec.push_back(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	compareVectorValues("vector elem", ft_vec, std_vec);

	std::cout << GREEN << "FT  at() vector: " << RESET;
	for (size_t i = 0; i < ft_vec.size(); i++) 
		std::cout << ft_vec.at(i) << " ";
	std::cout << std::endl;

	std::cout << GREEN << "STD at() vector: " << RESET;
	for (size_t i = 0; i < std_vec.size(); i++) 
		std::cout << std_vec.at(i) << " ";
	std::cout << std::endl << std::endl;

	compareValues("front elem vector", ft_vec.front(), std_vec.front());
	compareValues("back elem vector", ft_vec.back(), std_vec.back());
}

void testVectorSpeed() 
{
	{
		ft::vector<int> ft_vec;

		unsigned int start_time = clock();
		for (int i = 0; i < 100000000; i++) {
			ft_vec.push_back(i);
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "FT  vector push_back: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl;
	}
	//
	{
		std::vector<int> std_vec;

		unsigned int start_time = clock();
		for (int i = 0; i < 100000000; i++) {
			std_vec.push_back(i);
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "STD vector push_back: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl<<std::endl;
	}
	//
	{
		ft::vector<int> ft_vec;

		for (int i = 0; i < 100000000; i++) {
			ft_vec.push_back(i);
		}
		unsigned int start_time = clock();
		for (int i = 0; i < 100000000; i++) {
			ft_vec.pop_back();
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "FT  vector pop_back:  " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl;
	}
	//
	{
		std::vector<int> std_vec;

		for (int i = 0; i < 100000000; i++) {
			std_vec.push_back(i);
		}
		unsigned int start_time = clock();
		for (int i = 0; i < 100000000; i++) {
			std_vec.pop_back();
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "STD vector pop_back:  " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl;
	}
}

void vectorTest() 
{
	std::cout << LMAGENTA << LINE << RESET << std::endl;
	std::cout << LMAGENTA << VECTOR_LINE << RESET << std::endl;
	std::cout << LMAGENTA << LINE << RESET << std::endl;

	printHeader(LINE_SIZE, MAGENTA, "ITERATOR TEST");
	testVectorIterator();

	printHeader(LINE_SIZE, MAGENTA, "CAPACITY TEST");
	testVectorCapacity();

	printHeader(LINE_SIZE, MAGENTA, "ELEMENT ACCESS");
	testVectorElementAccess();

	printHeader(LINE_SIZE, MAGENTA, "MODIFIERS");
	testVectorModifiers();

	printHeader(LINE_SIZE, MAGENTA, "SPEED");
	testVectorSpeed();

	std::cout << LMAGENTA << LINE << RESET << std::endl;
}