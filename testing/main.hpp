#ifndef LAUNCHTEST_HPP
# define LAUNCHTEST_HPP

# include	<iostream>
# include	<sstream>

# include	<stack>
# include	<vector>
# include	<map>
# include	<set>

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

template <typename FtMap, typename StdMap>
void	compareMapValues(std::string description, FtMap ft_map, StdMap std_map)
{
	std::cout << GREEN << "STD " << description << ":" << RESET;
	for (size_t i = 0; i < std_map.size(); i++)
	{
		std::cout << "[" << std_map->first << "]" << " " << std_map->second << " | ";
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "FT  " << description << ":" << RESET;
	for (size_t i = 0; i < ft_map.size(); i++) 
	{
		std::cout << "[" << ft_map->first << "]" << " " << ft_map->second << " | ";
	}
	std::cout << std::endl << std::endl;
}

template <typename IterFt, typename IterStd>
void    compareMapValues(std::string description, IterFt ft_begin, IterFt ft_end, IterStd std_begin, IterStd std_end)
{
	std::cout << GREEN << "STD " << description << ":" << RESET;
	for (; std_begin < std_end; ++std_begin)
	{
		std::cout << "[" << std_begin->first << "]" << " " << std_begin->second << " | ";
	}
	std::cout << std::endl;
	
	std::cout << GREEN << "FT  " << description << ":" << RESET;
	for (; ft_begin < ft_end; ++ft_begin)
	{
		std::cout << "[" << ft_begin->first << "]" << " " << ft_begin->second << " | ";
	}
	std::cout << std::endl << std::endl;
}

void	printHeader(int sizeOfLine, std::string color, std::string name);

void	vectorTest();
void	stackTest();
void	mapTest();
void	setTest();

#endif