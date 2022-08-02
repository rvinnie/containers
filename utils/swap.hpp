#ifndef SWAP_HPP
#define SWAP_HPP

namespace ft 
{
	template <typename T>
	void swap(T &left, T &right)
	{
		T tmp = left;
		left = right;
		right = tmp;
	}
}

#endif