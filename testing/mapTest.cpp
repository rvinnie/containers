#include "main.hpp"

#include <map>
#include <iostream>
#include "../containers/map.hpp"

void testMapIterator() 
{
    int val;
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;

    std::cout << GREEN << "Map elem: " << RESET;
    for (int i = 0; i <= 10; i++)
	{
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;

	compareMapValues("iterator", ft_map.begin(), ft_map.end(), std_map.begin(), std_map.end());
	compareMapValues("reverse iterator", ft_map.rbegin(), ft_map.rend(), std_map.rbegin(), std_map.rend());
}

void testMapCapacity() 
{
    int val;
    std::map<int, int> std_map;
    ft::map<int, int> ft_map;
	compareValues("map empty", ft_map.empty(), std_map.empty());

    std::cout << GREEN << "Map elem: " << RESET;
    for (int i = 0; i <= 10; i++)
	{
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
    std::cout << std::endl << std::endl;

	compareValues("map size", ft_map.size(), std_map.size());
	compareValues("map max size", ft_map.max_size(), std_map.max_size());
}

void testMapElementAccess() 
{
	int val;
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

    std::cout << GREEN << "Map elem: " << RESET;
    for (int i = 0; i <= 10; i++)
	{
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;

	compareMapValues("map elements", ft_map, std_map);

    int j = 10;
    for (int i = 0; i <= 5; ++i)
	{
        ft_map[i] = ft_map[j];
        std_map[i] = std_map[j];
        j--;
    }

	compareMapValues("map elements", ft_map, std_map);
}

void testMapModifiers() 
{
	int val;
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

    std::cout << GREEN << "Map insert elem: " << RESET;
    for (int i = 0; i <= 3; i++)
	{
        val = rand() % 10;
        std_map.insert(std::pair<int,int>(i, val));
        ft_map.insert(ft::pair<int,int>(i, val));
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;
	
	compareMapValues("map elements", ft_map, std_map);

	ft_map.insert(ft_map.begin(), ft::pair<int,int>(4,777));
	std_map.insert(std_map.begin(), std::pair<int,int>(4,777));
	compareMapValues("map elements", ft_map, std_map);

	std::map<int, int> std_map1;
	ft::map<int, int> ft_map1;

    std::cout << GREEN << "Map insert elem: " << RESET;
    for (int i = 5; i <= 10; i++)
	{
        val = rand() % 10;
        std_map1.insert(std::pair<int,int>(i, val));
        ft_map1.insert(ft::pair<int,int>(i, val));
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;

	ft_map.insert(ft_map1.begin(), ft_map1.end());
	std_map.insert(std_map1.begin(), std_map1.end());
	compareMapValues("map elements", ft_map, std_map);

	ft_map.erase(ft_map.begin());
	std_map.erase(std_map.begin());
	compareMapValues("map elements after erase", ft_map, std_map);

	ft_map.erase(5);
	std_map.erase(5);
	compareMapValues("map elements after erase", ft_map, std_map);

	ft::map<int, int>::iterator ft_it = ft_map.find(8);
	std::map<int, int>::iterator std_it = std_map.find(8);

	ft_map.erase(ft_map.begin(), ft_it);
	std_map.erase(std_map.begin(), std_it);
	compareMapValues("map elements after erase", ft_map, std_map);

	ft_map.swap(ft_map1);
	std_map.swap(std_map1);
	compareMapValues("map elements after swap", ft_map, std_map);

	ft_map.clear();
	std_map.clear();
	compareMapValues("map elements after clear", ft_map, std_map);
}

void testMapObserversModifiers() 
{
	{
		ft::map<char,int> ft_map;
		std::map<char,int> std_map;

		ft::map<char,int>::key_compare ft_comp = ft_map.key_comp();
		std::map<char,int>::key_compare std_comp = std_map.key_comp();

		ft_map['q'] = 777;
		ft_map['w'] = 888;
		ft_map['e'] = 999;
		std_map['q'] = 777;
		std_map['w'] = 888;
		std_map['e'] = 999;

		char ft_highest = ft_map.rbegin()->first;    
		char std_highest = std_map.rbegin()->first;   

		std::cout << GREEN << "FT  map elements: " << RESET;
		ft::map<char,int>::iterator ft_it = ft_map.begin();
		do
		{
			std::cout << "[" << RED << ft_it->first << RESET << "-" << ft_it->second << "] ";
		} while ( ft_comp((*ft_it++).first, ft_highest) );
		std::cout << std::endl;

		std::cout << GREEN << "STD map elements: " << RESET;
		std::map<char,int>::iterator std_it = std_map.begin();
		do
		{
			std::cout << "[" << RED << std_it->first << RESET << "-" << std_it->second << "] ";
		} while ( std_comp((*std_it++).first, std_highest) );
		std::cout << std::endl << std::endl;
	}
	{
		ft::map<char,int> ft_map;
		std::map<char,int> std_map;

		ft_map['q'] = 1212;
		ft_map['w'] = 2323;
		ft_map['e'] = 3434;
		std_map['q'] = 1212;
		std_map['w'] = 2323;
		std_map['e'] = 3434;

		ft::pair<char,int> ft_highest = *ft_map.rbegin();
		std::pair<char,int> std_highest = *std_map.rbegin();
		std::cout << GREEN << "FT map elements:   " << RESET;
		ft::map<char,int>::iterator ft_it = ft_map.begin();
		do
		{
			std::cout << "[" << RED << ft_it->first << RESET << "-" << ft_it->second << "] ";
		} while ( ft_map.value_comp()(*ft_it++, ft_highest) );
		std::cout << std::endl;

		std::cout << GREEN << "STD map elements:  " << RESET;
		std::map<char,int>::iterator std_it = std_map.begin();
		do
		{
			std::cout << "[" << RED << std_it->first << RESET << "-" << std_it->second << "] ";
		} while ( std_map.value_comp()(*std_it++, std_highest) );
		std::cout << std::endl << std::endl;
	}
}

void testMapOperationsModifiers() 
{
	int val;
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

    std::cout << GREEN << "Map elem: " << RESET;
    for (int i = 0; i <= 5; i++)
	{
        val = rand() % 10;
        std_map[i] = val;
        ft_map[i] = val;
        std::cout << val << " ";
    }
	std::cout << std::endl << std::endl;
	
	std::cout << GREEN << "FT  map find elements: " << RESET;
	for (int i = 0; i <= 5; i++)
	{
		if (ft_map.count(i))
		{
			std::cout << "[" << RED << ft_map.find(i)->first << RESET << "-" << ft_map.find(i)->second << "] ";
		}
	}
	std::cout << std::endl;

	std::cout << GREEN << "STD map find elements: " << RESET;
	for (int i = 0; i <= 5; i++)
	{
		if (std_map.count(i))
		{
			std::cout << "[" << RED << std_map.find(i)->first << RESET << "-" << std_map.find(i)->second << "] ";
		}
	}
	std::cout << std::endl << std::endl;

	ft::map<int, int>::iterator ft_it = ft_map.begin();
	std::cout << GREEN << "FT  map upper_bound: " << RESET;
	ft_it = ft_map.upper_bound(4);
	std::cout << "[" << RED << ft_it->first << RESET << "-" << ft_it->second << "] " << std::endl;

	std::map<int, int>::iterator std_it = std_map.begin();
	std::cout << GREEN << "STD map upper_bound: " << RESET;
	std_it = std_map.upper_bound(4);
	std::cout << "[" << RED << std_it->first << RESET << "-" << std_it->second << "] " << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN << "FT  map lower_bound: " << RESET;
	ft_it = ft_map.lower_bound(4);
	std::cout << "[" << RED << ft_it->first << RESET << "-" << ft_it->second << "] " << std::endl;

	std::cout << GREEN << "STD map lower_bound: " << RESET;
	std_it = std_map.lower_bound(4);
	std::cout << "[" << RED << std_it->first << RESET << "-" << std_it->second << "] " << std::endl << std::endl;

	std::cout << GREEN << "FT  map equal_range: " << RESET;
	ft::pair<ft::map<int,int>::iterator, ft::map<int,int>::iterator> ft_ret = ft_map.equal_range(3);
	std::cout << "[" << RED << ft_ret.first->first << RESET << "-" << ft_ret.second->second << "] " << std::endl;

	std::cout << GREEN << "STD map equal_range: " << RESET;
	std::pair<std::map<int,int>::iterator, std::map<int,int>::iterator> std_ret = std_map.equal_range(3);
	std::cout << "[" << RED << std_ret.first->first << RESET << "-" << std_ret.second->second << "] " << std::endl << std::endl;
}

void testMapSpeed()
{
	{
		ft::map<int, int> ft_map;

		unsigned int start_time = clock();
		for (int i = 0; i < 10000000; i++) {
			ft_map.insert(ft::pair<int, int>(i, i));
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "FT  map insert: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl;
	}
	//
	{
		std::map<int, int> std_map;

		unsigned int start_time = clock();
		for (int i = 0; i < 10000000; i++)
		{
			std_map.insert(std::pair<int, int>(i, i));
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "STD map insert: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl<<std::endl;
	}
	//
	{
		ft::map<int, int> ft_map;

		for (int i = 0; i < 10000000; i++)
		{
			ft_map.insert(ft::pair<int, int>(i, i));
		}
		unsigned int start_time = clock();
		for (int i = 10000000; i > 0; i--)
		{
			ft_map.erase(i);
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "FT  map erase: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl;
	}
	//
	{
		std::map<int, int> std_map;

		for (int i = 0; i < 10000000; i++)
		{
			std_map.insert(std::pair<int, int>(i, i));
		}
		unsigned int start_time = clock();
		for (int i = 10000000; i > 0; i--)
		{
			std_map.erase(i);
		}
		unsigned int end_time = clock();

		std::cout << GREEN << "STD map erase: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl << std::endl;
	}
	//
	{
		ft::map<int, int> ft_map;

		for (int i = 0; i < 10000000; i++)
		{
			ft_map.insert(ft::pair<int, int>(i, i));
		}

		unsigned int start_time = clock();
		ft_map.find(10000000);
		unsigned int end_time = clock();

		std::cout << GREEN << "FT  map find: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl;
	}
	//
	{
		std::map<int, int> std_map;

		for (int i = 0; i < 10000000; i++)
		{
			std_map.insert(std::pair<int, int>(i, i));
		}
		
		unsigned int start_time = clock();
		std_map.find(10000000);
		unsigned int end_time = clock();

		std::cout << GREEN << "STD  map find: " << RESET; 
		std::cout << difftime_in_ms(start_time, end_time) << " ms" << std::endl;
	}
}

void mapTest()
{
	std::cout << LGREEN << LINE << RESET << std::endl;
	std::cout << LGREEN << MAP_LINE << RESET << std::endl;
	std::cout << LGREEN << LINE << RESET << std::endl;

	printHeader(LINE_SIZE, GREEN, "ITERATOR TEST");
	testMapIterator();

	printHeader(LINE_SIZE, GREEN, "CAPACITY TEST");
	testMapCapacity();

	printHeader(LINE_SIZE, GREEN, "ELEMENT ACCESS");
	testMapElementAccess();

	printHeader(LINE_SIZE, GREEN, "MODIFIERS");
	testMapModifiers();

	printHeader(LINE_SIZE, GREEN, "OBSERVERS MODIFIERS");
	testMapObserversModifiers();

	printHeader(LINE_SIZE, GREEN, "OPERATIONS MODIFIERS");
	testMapOperationsModifiers();

	printHeader(LINE_SIZE, GREEN, "SPEED");
	testMapSpeed();

	std::cout << LGREEN << LINE << std::endl << LINE << std::endl;
}