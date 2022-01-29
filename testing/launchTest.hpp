#ifndef LAUNCHTEST_HPP
# define LAUNCHTEST_HPP

# define RED     "\x1b[31m"
# define LRED  "\x1b[1;31m"
# define GREEN   "\x1b[32m"
# define LGREEN  "\x1b[1;32m"
# define GREENBACK "\x1b[2;30;42m"

# define BLUE    "\x1b[34m"

# define CYAN    "\x1b[36m"
# define RESET   "\x1b[0m"


# define SET_LINE    "------- SET TESTS -------"

# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <sstream>

# include <vector>
# include <stack>
# include <map>
# include <set>


void vectorTest();
void stackTest();
void mapTest();
void setTest();

#endif