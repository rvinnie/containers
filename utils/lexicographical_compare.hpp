#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft 
{
	template <class InputIterator>
	bool	lexicographical_compare(InputIterator firstLeft, InputIterator lastLeft,
								    InputIterator firstRight, InputIterator lastRight)
    {
		while (firstLeft != lastLeft)
        {
			if (firstRight == lastRight || *firstRight < *firstLeft)
				return (false);
			else if (*firstLeft < *firstRight)
				return (true);
			++firstLeft;
			++firstRight;
		}
		return (firstRight != lastRight);
	}
}

#endif
