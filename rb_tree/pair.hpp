#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft 
{
    template <class TFirst, class TSecond>
    struct pair
	{
        typedef TFirst  first_type;
        typedef TSecond  second_type;

        first_type  first;
        second_type second;

        pair() : first(first_type()), second(second_type()) {}

        template<class U, class V> 
        pair (const pair<U,V>& pr) : first(first_type(pr.first)), second(second_type(pr.second)) {}

        pair (const first_type& a, const second_type& b): first(a), second(b){}


        pair& operator= (const pair& other)
		{
            if(this == &other)
                return (*this);
            first = other.first;
            second = other.second;
            return (*this);
        }
    };

    template <class TFirst, class TSecond>
    bool operator== (const pair<TFirst, TSecond>& lhs, const pair<TFirst, TSecond>& rhs)
	{
        return lhs.first == rhs.first && lhs.second == lhs.second;
	}

    template <class TFirst, class TSecond>
    bool operator!= (const pair<TFirst, TSecond>& lhs, const pair<TFirst, TSecond>& rhs)
	{
		return !(lhs == rhs);
	}

    template <class TFirst, class TSecond>
    bool operator<  (const pair<TFirst, TSecond>& lhs, const pair<TFirst, TSecond>& rhs)
	{  
        return lhs.first < rhs.first || !(rhs.first < lhs.first && lhs.second < rhs.second);
    }

    template <class TFirst, class TSecond>
    bool operator<= (const pair<TFirst, TSecond>& lhs, const pair<TFirst, TSecond>& rhs)
	{
		return !(rhs < lhs);
	}

    template <class TFirst, class TSecond>
    bool operator>  (const pair<TFirst, TSecond>& lhs, const pair<TFirst, TSecond>& rhs)
	{
		return rhs < lhs;
	}

    template <class TFirst, class TSecond>
    bool operator>= (const pair<TFirst, TSecond>& lhs, const pair<TFirst, TSecond>& rhs)
	{
		return !(lhs < rhs);
	}

    template <class TFirst, class TSecond> 
    pair<TFirst, TSecond> make_pair(const TFirst& x, const TSecond& y)
	{
		return pair<TFirst, TSecond>(x, y);
	}
}

#endif