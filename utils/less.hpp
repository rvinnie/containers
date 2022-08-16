#ifndef LESS_HPP
#define LESS_HPP

namespace ft
{
	template <class Left, class Right, class Result>
  	struct binary_function
	{
    	typedef Left 	first_argument_type;
    	typedef Right 	second_argument_type;
    	typedef Result 	result_type;
  	};

	template <class T> 
	struct less : binary_function <T, T, bool>
	{
  		bool operator() (const T& left, const T& right) const
		{
			return (left < right);
		}
	};
} 

#endif