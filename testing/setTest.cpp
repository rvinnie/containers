#include "main.hpp"

#include <set>
#include <iostream>
#include "../containers/set.hpp"

void testSetIterator() 
{
	int val;
	std::set<int> std_set;
	ft::set<int> ft_set;

	std::cout << GREEN << "Set elem: " << RESET;
	for (int i = 0; i <= 10; i++)
	{
		val = rand() % 10;
		std_set.insert(val);
		ft_set.insert(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	compareSetValues("iterator", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());
	compareSetValues("reverse iterator", ft_set.rbegin(), ft_set.rend(), std_set.rbegin(), std_set.rend());
}

void testSetCapacity() 
{
	int val;
	std::set<int> std_set;
	ft::set<int> ft_set;
	compareValues("set empty", ft_set.empty(), std_set.empty());

	std::cout << GREEN << "Set elem: " << RESET;
	for (int i = 0; i <= 10; i++)
	{
		val = rand() % 10;
		std_set.insert(val);
		ft_set.insert(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	compareValues("set size", ft_set.size(), std_set.size());
}

void testSetElementAccess() 
{
	int val;
	std::set<int> std_set;
	ft::set<int> ft_set;

	std::cout << GREEN << "Set elem: " << RESET;
	for (int i = 0; i <= 10; i++)
	{
		val = rand() % 10;
		std_set.insert(val);
		ft_set.insert(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	compareSetValues("set elements", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());
}

void testSetModifiers() 
{
	int val;
	std::set<int> std_set;
	ft::set<int> ft_set;

	std::cout << GREEN << "Set insert elem: " << RESET;
	for (int i = 0; i <= 3; i++)
	{
		val = rand() % 10;
		std_set.insert(val);
		ft_set.insert(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	compareSetValues("set elements", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());

	ft_set.insert(ft_set.begin(), 333);
	std_set.insert(std_set.begin(), 333);
	compareSetValues("set elements", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());

	std::set<int> std_set1;
	ft::set<int> ft_set1;

	std::cout << GREEN << "Set insert elem: " << RESET;
	for (int i = 5; i <= 10; i++)
	{
		val = rand() % 10;
		std_set1.insert(val);
		ft_set1.insert(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	ft_set.insert(ft_set1.begin(), ft_set1.end());
	std_set.insert(std_set1.begin(), std_set1.end());
	compareSetValues("set elements", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());

	ft_set.erase(ft_set.begin());
	std_set.erase(std_set.begin());
	compareSetValues("set elements after erase", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());

	ft_set.erase(5);
	std_set.erase(5);
	compareSetValues("set elements after erase", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());

	ft::set<int>::iterator ft_it = ft_set.find(8);
	std::set<int>::iterator std_it = std_set.find(8);

	ft_set.erase(ft_set.begin(), ft_it);
	std_set.erase(std_set.begin(), std_it);
	compareSetValues("set elements after erase", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());

	ft_set.swap(ft_set1);
	std_set.swap(std_set1);
	compareSetValues("set elements after swap", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());

	ft_set.clear();
	std_set.clear();
	compareSetValues("set elements after clear", ft_set.begin(), ft_set.end(), std_set.begin(), std_set.end());
}

void testSetObserversModifiers() 
{
	{
		ft::set<int> ft_set;
		std::set<int> std_set;

		ft::set<int>::key_compare ft_comp = ft_set.key_comp();
		std::set<int>::key_compare std_comp = std_set.key_comp();

		ft_set.insert(777);
		ft_set.insert(888);
		ft_set.insert(999);
		std_set.insert(777);
		std_set.insert(888);
		std_set.insert(999);

		int ft_highest = *ft_set.rbegin(); 
		int std_highest = *std_set.rbegin();   

		std::cout << GREEN << "FT  set elements: " << RESET;
		ft::set<int>::iterator ft_it = ft_set.begin();
		do
		{
			std::cout << *ft_it << " " ;
		} while ( ft_comp((*ft_it++), ft_highest) );
		std::cout << std::endl;

		std::cout << GREEN << "STD set elements: " << RESET;
		std::set<int>::iterator std_it = std_set.begin();
		do
		{
			std::cout << *std_it << " " ;
		} while ( std_comp((*std_it++), std_highest) );
		std::cout << std::endl << std::endl;
	}
	{
		ft::set<char> ft_set;
		std::set<char> std_set;

		ft_set.insert('q');
		ft_set.insert('w');
		ft_set.insert('e');
		std_set.insert('q');
		std_set.insert('w');
		std_set.insert('e');

		int ft_highest = *ft_set.rbegin();
		int std_highest = *std_set.rbegin();
		std::cout << GREEN << "FT set elements:   " << RESET;
		ft::set<char>::iterator ft_it = ft_set.begin();
		do
		{
			std::cout << *ft_it << " ";
		} while ( ft_set.value_comp()(*ft_it++, ft_highest) );
		std::cout << std::endl;

		std::cout << GREEN << "STD set elements:  " << RESET;
		std::set<char>::iterator std_it = std_set.begin();
		do
		{
			std::cout << *std_it << " " ;
		} while ( std_set.value_comp()(*std_it++, std_highest) );
		std::cout << std::endl << std::endl;
	}
}

void testSetOperationsModifiers() 
{
	int val;
	std::set<int> std_set;
	ft::set<int> ft_set;

	std::cout << GREEN << "Set elem: " << RESET;
	for (int i = 0; i <= 5; i++)
	{
		val = rand() % 10;
		std_set.insert(val);
		ft_set.insert(val);
		std::cout << val << " ";
	}
	std::cout << std::endl << std::endl;

	std::cout << GREEN << "FT  set find elements: " << RESET;
	for (int i = 0; i <= 5; i++)
	{
		if (ft_set.count(i))
		{
			std::cout << *ft_set.find(i) << " ";
		}
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD set find elements: " << RESET;
	for (int i = 0; i <= 5; i++)
	{
		if (std_set.count(i))
		{
			std::cout << *std_set.find(i) << " ";
		}
	}
	std::cout << std::endl << std::endl;

	ft::set<int>::iterator ft_it = ft_set.begin();
	std::cout << GREEN << "FT  set upper_bound: " << RESET;
	ft_it = ft_set.upper_bound(4);
	std::cout << *ft_it << " " << std::endl;

	std::set<int>::iterator std_it = std_set.begin();
	std::cout << GREEN << "STD set upper_bound: " << RESET;
	std_it = std_set.upper_bound(4);
	std::cout << *std_it << " " << std::endl;
	std::cout << std::endl;

	std::cout << GREEN << "FT  set lower_bound: " << RESET;
	ft_it = ft_set.lower_bound(4);
	std::cout << *ft_it << " " << std::endl;

	std::cout << GREEN << "STD set lower_bound: " << RESET;
	std_it = std_set.lower_bound(4);
	std::cout << *std_it << " " << std::endl;

	std::cout << GREEN << "FT  set equal_range: " << RESET;
	ft::pair<ft::set<int>::iterator, ft::set<int>::iterator> ft_ret = ft_set.equal_range(3);
	std::cout << *ft_ret.first << " " << *ft_ret.second << std::endl;

	std::cout << GREEN << "STD set equal_range: " << RESET;
	std::pair<std::set<int>::iterator, std::set<int>::iterator> std_ret = std_set.equal_range(3);
	std::cout << *ft_ret.first << " " << *std_ret.second << std::endl;
}

void testSetSpeed()
{
	{
		ft::set<int> ft_set;

		unsigned int start_time = clock();
		for (int i = 0; i < 10000000; i++)
		{
			ft_set.insert(i);
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "FT  set insert: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " sec" << std::endl;
	}
	//
	{
		std::set<int> std_set;

		unsigned int start_time = clock();
		for (int i = 0; i < 10000000; i++)
		{
			std_set.insert(i);
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "STD set insert: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl<<std::endl;
	}
	//
	{
		ft::set<int> ft_set;

		for (int i = 0; i < 10000000; i++)
		{
			ft_set.insert(i);
		}
		unsigned int start_time = clock();
		for (int i = 10000000; i > 0; i--)
		{
			ft_set.erase(i);
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "FT  set erase: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " sec" << std::endl;
	}
	//
	{
		std::set<int> std_set;

		for (int i = 0; i < 10000000; i++)
		{
			std_set.insert(i);
		}
		unsigned int start_time = clock();
		for (int i = 10000000; i > 0; i--)
		{
			std_set.erase(i);
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "STD set erase: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl << std::endl;
	}
	//
	{
		ft::set<int> ft_set;

		for (int i = 0; i < 10000000; i++)
		{
			ft_set.insert(i);
		}

		unsigned int start_time = clock();
		ft_set.find(10000000);
		unsigned int end_time = clock();

		std::cout << GREEN << "FT  set find: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl;
	}
	//
	{
		std::set<int> std_set;

		for (int i = 0; i < 10000000; i++)
		{
			std_set.insert(i);
		}

		unsigned int start_time = clock();
		std_set.find(10000000);
		unsigned int end_time = clock();

		std::cout << GREEN << "STD  set find: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl;
	}
}

void setTest()
{
	std::cout << LCYAN << LINE << RESET << std::endl;
	std::cout << LCYAN << SET_LINE << RESET << std::endl;
	std::cout << LCYAN << LINE << RESET << std::endl;

	printHeader(LINE_SIZE, CYAN, "ITERATOR TEST");
	testSetIterator();

	printHeader(LINE_SIZE, CYAN, "CAPACITY TEST");
	testSetCapacity();

	printHeader(LINE_SIZE, CYAN, "ELEMENT ACCESS");
	testSetElementAccess();

	printHeader(LINE_SIZE, CYAN, "MODIFIERS");
	testSetModifiers();

	printHeader(LINE_SIZE, CYAN, "OBSERVERS MODIFIERS");
	testSetObserversModifiers();

	printHeader(LINE_SIZE, CYAN, "OPERATIONS MODIFIERS");
	testSetOperationsModifiers();

	printHeader(LINE_SIZE, CYAN, "SPEED");
	testSetSpeed();

	std::cout << LCYAN << LINE << std::endl << LINE << std::endl;
}