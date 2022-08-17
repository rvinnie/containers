#ifndef LAUNCHTEST_HPP
# define LAUNCHTEST_HPP

# include	<iostream>
# include	<sstream>

# include	<stack>
# include	<vector>
# include	<map>
# include	<set>
# include   <time.h>

# include	"../containers/stack.hpp"
# include	"../containers/vector.hpp"
# include	"../containers/map.hpp"
# include	"../containers/set.hpp"

# define RESET			"\x1b[0m"
# define MAGENTA		"\x1b[35m"
# define LMAGENTA		"\x1b[1;35m"
# define YELLOW			"\x1b[33m"
# define LYELLOW		"\x1b[1;33m"
# define CYAN			"\x1b[36m"
# define LCYAN			"\x1b[1;36m"
# define GREEN			"\x1b[32m"
# define LGREEN			"\x1b[1;32m"
# define RED				"\033[31m"

# define LINE_SIZE		41
# define LINE			"-----------------------------------------"
# define VECTOR_LINE	"------------- VECTOR TESTS --------------"
# define STACK_LINE		"-------------- STACK TESTS --------------"
# define SET_LINE		"--------------- SET TESTS ---------------"
# define MAP_LINE		"--------------- MAP TESTS ---------------"

template <typename T>
void	compareValues(std::string description, T ftValue, T stdValue)
{
	std::cout << GREEN << "STD " << description << ": " << RESET << stdValue << std::endl;
	std::cout << GREEN << "FT  " << description << ": " << RESET << ftValue << std::endl << std::endl;
}

template <typename FtVector, typename StdVector>
void	compareVectorValues(std::string description, FtVector ft_vector, StdVector std_vector)
{
	std::cout << GREEN << "STD " << description << ":" << RESET;
	for (size_t i = 0; i < std_vector.size(); i++)
	{
		std::cout << " " << std_vector[i];
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "FT  " << description << ":" << RESET;
	for (size_t i = 0; i < ft_vector.size(); i++) 
	{
		std::cout << " " << ft_vector[i];
	}
	std::cout << std::endl << std::endl;
}

template <typename IterFt, typename IterStd>
void    compareVectorValues(std::string description, IterFt ft_begin, IterFt ft_end, IterStd std_begin, IterStd std_end)
{
	std::cout << GREEN << "STD " << description << ":" << RESET;
	for (; std_begin < std_end; ++std_begin)
	{
		std::cout << " " << *std_begin;
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "FT  " << description << ":" << RESET;
	for (; ft_begin < ft_end; ++ft_begin)
	{
		std::cout << " " << *ft_begin;
	}
	std::cout << std::endl << std::endl;
}

// void	compareSetValues(std::string description, ft::set<int> ft_set, std::set<int> std_set)
// {
// 	std::cout << GREEN << "STD " << description << ":" << RESET;
// 	ft::set<int>::iterator ft_it = ft_set.begin();
// 	for (;ft_it != ft_set.end(); ++ft_it)
// 	{
// 		std::cout << *ft_it << " " ;
// 	}
// 	std::cout << std::endl;
	
// 	std::cout << GREEN << "FT  " << description << ":" << RESET;
// 	std::set<int>::iterator std_it = std_set.begin();
// 	for (;std_it != std_set.end(); ++std_it) 
// 	{
// 		std::cout << *std_it << " " ;
// 	}
// 	std::cout << std::endl << std::endl;
// }

template <typename IterFt, typename IterStd>
void    compareSetValues(std::string description, IterFt ft_begin, IterFt ft_end, IterStd std_begin, IterStd std_end)
{
	std::cout << GREEN << "STD " << description << ":" << RESET;
	for (; std_begin != std_end; ++std_begin)
	{
		std::cout << " " << *std_begin;
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "FT  " << description << ":" << RESET;
	for (; ft_begin != ft_end; ++ft_begin)
	{
		std::cout << " " << *ft_begin;
	}
	std::cout << std::endl << std::endl;
}

template <typename FtMap, typename StdMap>
void	compareMapValues(std::string description, FtMap ft_map, StdMap std_map)
{
	std::cout << GREEN << "STD " << description << ":" << RESET << std::endl;
	std::map<int, int>::iterator std_it = std_map.begin();
	for (;std_it != std_map.end(); ++std_it)
	{
		std::cout << "[" << RED << std_it->first << RESET << "-" << std_it->second << "] ";
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "FT  " << description << ":" << RESET << std::endl;
	ft::map<int, int>::iterator ft_it = ft_map.begin();
	for (;ft_it != ft_map.end(); ++ft_it) 
	{
		std::cout << "[" << RED << ft_it->first << RESET << "-" << ft_it->second << "] ";
	}
	std::cout << std::endl << std::endl;
}

template <typename IterFt, typename IterStd>
void    compareMapValues(std::string description, IterFt ft_begin, IterFt ft_end, IterStd std_begin, IterStd std_end)
{
	std::cout << GREEN << "STD " << description << ":" << RESET << std::endl;
	for (; std_begin != std_end; ++std_begin)
	{
		std::cout << "[" << RED << std_begin->first << RESET << "-" << std_begin->second << "] ";
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "FT  " << description << ":" << RESET << std::endl;
	for (; ft_begin != ft_end; ++ft_begin)
	{
		std::cout << "[" << RED << ft_begin->first << RESET << "-" << ft_begin->second << "] ";
	}
	std::cout << std::endl << std::endl;
}

void	printHeader(int sizeOfLine, std::string color, std::string name);
double	difftime_in_ms(unsigned int start_time, unsigned int end_time);

void	vectorTest();
void	stackTest();
void	mapTest();
void	setTest();

#endif