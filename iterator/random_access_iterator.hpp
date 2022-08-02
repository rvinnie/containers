#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include <iterator>

namespace ft 
{
	template <class ValueType>
	class random_access_iterator : public std::iterator<std::random_access_iterator_tag, ValueType>
	{
	public:
		typedef ValueType													value_type;
		typedef ValueType*													pointer;
		typedef ValueType&													reference;
		typedef typename std::random_access_iterator_tag					iterator_category;
		typedef std::ptrdiff_t												difference_type;

		random_access_iterator()
		{
			_ptr = NULL;
		}

		random_access_iterator(pointer ptr) 
		{
			_ptr = ptr;
		}

		random_access_iterator(random_access_iterator<ValueType> const &rhs)
		{
			_ptr = rhs.getPointer();
		}

		virtual ~random_access_iterator() {}

		pointer pointer() const
		{
			return _ptr;
		}

		random_access_iterator		&operator=(const It &rhs) {
			if (this == &rhs)
				return *this;
			this->_ptr = rhs._ptr;
			return *this;
		}

		reference					operator*()
		{
			return *this->_ptr;
		}
	
		pointer						operator->()
		{
			return this->_ptr;
		}

		reference					operator[](difference_type index)
		{
			return this->_ptr[index];
		}

		random_access_iterator&		operator++() // pre-increment
        {
			++this->_ptr;
			return *this;
		}

		random_access_iterator&		operator--()
		{
			--this->_ptr;
			return *this;
		}

		random_access_iterator		operator++(int)  // post-increment
		{
			random_access_iterator it(*this);
			++this->_ptr;
			return it;
		}

		random_access_iterator		operator--(int)
		{
			random_access_iterator it(*this);
			--this->_ptr; 
			return it;
		}

		random_access_iterator		operator+(difference_type n) const
		{
			return random_access_iterator(this->_ptr + n);
		}

		random_access_iterator		operator-(difference_type n) const
		{
			return random_access_iterator(this->_ptr - n);
		}

		random_access_iterator&		operator+=(difference_type n) const
		{
			return random_access_iterator(this->_ptr += n);
		}

		random_access_iterator&		operator-=(difference_type n) const
		{
			return random_access_iterator(this->_ptr -= n);
		}

	private:
		pointer		_ptr;
	};

	template <class ValueType>
	random_access_iterator<ValueType>	operator+(typename random_access_iterator<ValueType>::difference_type n, random_access_iterator<ValueType> &rhs)
	{
		return (rhs + n);	
	}
	
	template <class ValueType>
	typename random_access_iterator<ValueType>::difference_type operator-(const random_access_iterator<ValueType> &lhs, 
																		const random_access_iterator<ValueType> &rhs)
	{
		return (lhs.pointer() - rhs.pointer());
	}

	template <class ValueType>
	bool	operator==(const random_access_iterator<ValueType> &lhs, const random_access_iterator<ValueType> &rhs)
	{
		return (lhs.pointer() == rhs.pointer());
	}
	
	template <class ValueType>
	bool	operator!=(const random_access_iterator<ValueType> &lhs, const random_access_iterator<ValueType> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class ValueType>
	bool	operator>(const random_access_iterator<ValueType> &lhs, const random_access_iterator<ValueType> &rhs)
	{
		return (lhs.pointer() > rhs.pointer());
	}
	
	template <class ValueType>
	bool	operator<(const random_access_iterator<ValueType> &lhs, const random_access_iterator<ValueType> &rhs)
	{
		return (lhs.pointer() < rhs.pointer());
	}
	
	template <class ValueType>
	bool	operator>=(const random_access_iterator<ValueType> &lhs, const random_access_iterator<ValueType> &rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}

	template <class ValueType>
	bool	operator<=(const random_access_iterator<ValueType> &lhs, const random_access_iterator<ValueType> &rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}
}

#endif