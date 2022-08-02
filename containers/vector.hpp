#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft{

	template <class T, class Alloc = std::allocator<T>>
	class vector
	{
		public:
			// Member types
			typedef T value_type;
			typedef Alloc allocator_type;

			typedef typename std::size_t size_type;
			typedef typename ft::random_access_iterator<value_type>::difference_type difference_type;

			typedef typename ft::random_access_iterator<value_type> iterator;
			typedef typename ft::random_access_iterator<const value_type> const_iterator;

			typedef typename ft::reverse_iterator<iterator> reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;

			typedef typename allocator_type::reference reference;
			typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer pointer;
			typedef typename allocator_type::const_pointer const_pointer;

			// Member functions
			explicit vector (const allocator_type& alloc = allocator_type())
			{
				_allocator = alloc;
				_capacity = 0;
				_ptr = NULL;
				_size = 0;
			}

			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				_allocator = alloc;
				_size = n;
				_capacity = n;
				_ptr = _allocator.allocate(n);
				for (int i = 0; i < n; ++i)
				{
					_allocator.construct(_ptr + i, val);
				}
			}
			
			template <class InputIterator>
         	vector (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type())
			{
				_ptr = NULL;
				_allocator = alloc;
				_size = std::distance(first, last);
				_capacity = std::distance(first, last);
				_ptr = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i) {
					_allocator.construct(_ptr + i, *(first + i));
			}
			}

			vector (const vector& x)
			{
				_allocator = x._allocator;
				_size = x._size;
				_capacity = x._capacity;
				_ptr = _allocator.allocate(_capacity);
				for (int i = 0; i < _size; ++i)
				{
					_allocator.construct(_ptr + i, *(x._ptr + i));
				}
			}

			~vector()
			{
				for (int i = 0; i < _size; ++i)
				{
					_allocator.destroy(_ptr + i);
				}
				_allocator.deallocate(_ptr, _capacity);
				_ptr = NULL
			}

			//// Iterators
			iterator				begin()
			{
				return iterator(_ptr)
			}

			const_iterator			begin() const
			{
				return const_iterator(_ptr)
			}

			iterator				end()
			{
				return iterator(_ptr + _size);
			}

			const_iterator			end() const
			{
				return const_iterator(_ptr + _size);
			}

			reverse_iterator		rbegin()
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator	rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator		rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator	rend() const
			{
				return const_everse_iterator(begin());
			}

			//// Capacity
			size_type	size() const
			{
				return _size;
			}

			size_type	max_size() const
			{
				return _allocator.max_size();
			}

			void		resize (size_type n, value_type val = value_type())
			{
				if (n < _size)
					erase(begin() + n, end());
				else if (n > _size)
					insert(end(), n - size(), val);
			}

			size_type	capacity() const
			{
				return _capacity;
			}

			bool		empty() const
			{
				return _size == 0;
			}
			
			void		reserve (size_type n)
			{
				if (_capacity >= n)
					return;

				pointer ptr_tmp;
				ptr_tmp = _allocator.allocate(n);
				for (int i = 0; i < _size; ++i) {
					ptr_tmp[i] = _ptr[i];
				}

				if (_ptr != NULL)
					_allocator.deallocate(_ptr, _capacity);
				_ptr = ptr_tmp;
				_capacity = n;
			}

			//// Element access
			reference		operator[] (size_type n)
			{
				return *(begin() + n);
			}

			const_reference	operator[] (size_type n) const
			{
				return *(begin() + n);
			}

			reference		at (size_type n)
			{
				if (n >= _size)
					throw std::out_of_range("Index out of range.");
				return *(_ptr + n);
			}

			const_reference	at (size_type n) const
			{
				if (n >= _size)
					throw std::out_of_range("Index out of range.");
				return *(_ptr + n);
			}

			reference		front()
			{
				return *(begin());
			}

			const_reference	front() const
			{
				return *(begin());
			}

			reference		back()
			{
				return *(end() - 1);
			}

			const_reference	back() const
			{
				return *(end() - 1);
			}

			//// Modifiers
			template <class InputIterator>
			void			assign (InputIterator first, InputIterator last);

			void			assign (size_type n, const value_type& val);

			void			push_back (const value_type& val)
			{
				if (_size >= _capacity)
					this->reserve(_capacity * 2 + (_capacity == 0));

				_allocator.construct(this->end().pointer(), val);
				_size++;
			}

			void			pop_back()
			{
				if (_size == 0)
					return;
				_allocator.destroy(_ptr + _size - 1);
				_size--;
			}

			iterator		insert (iterator position, const value_type& val);

    		void			insert (iterator position, size_type n, const value_type& val);

			template <class InputIterator>
    		void			insert (iterator position, InputIterator first, InputIterator last);

			iterator		erase (iterator position)
			{
				vector tail(position + 1, end());
				for (size_type i = 0; i < tail.size(); i++)
					pop_back();
				pop_back();

				iterator it(tail.begin());

				while (it != tail.end())
				{
					push_back(*it);
					it++;
				}
				return position;
			}

			iterator		erase (iterator first, iterator last)
			{
				iterator it(first);
				while (it != last)
				{
					erase(first);
					it++;
				}
				return first;
			}

			void			swap (vector& x)
			{
				ft::swap(this->_ptr, x._ptr);
				ft::swap(this->_size, x._ptr);
				ft::swap(this->_capacity, x._capacity);
				ft::swap(this->_allocator, x._allocator);
			}
			
			void			clear()
			{
				if (_ptr == NULL)
					return;
				for (size_type i = 0; i < _size; ++i)
				{
					_allocator.destroy(_ptr + i);
					_size = 0;
				}
			}

			allocator_type	get_allocator() const
			{
				return this->_allocator;
			}

		private:
			pointer			_ptr;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_allocator;
	};

	// Non-member function overloads
	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return !(lhs == rhs);
	}

	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return !(rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return rhs < lhs;
	}

	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc>& lhs, const ft::vector<T, Alloc>& rhs)
	{
		return !(lhs < rhs);
	}

	template<class T, class Alloc>
	void swap(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#endif