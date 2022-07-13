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
			typedef typename std::random_access_iterator<T, T*, T&>::difference_type difference_type;

			typedef typename std::random_access_iterator<T, T*, T&> iterator;
			typedef typename std::random_access_iterator<T, const T*, const T&> const_iterator;

			typedef typename std::reverse_iterator<iterator> reverse_iterator;
			typedef typename std::reverse_iterator<const_iterator> const_reverse_iterator;

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
         	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) // enable_if ...
			{
				//...
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
			iterator				begin();
			const_iterator			begin() const;

			iterator				end();
			const_iterator			end() const;

			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;

			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

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
			reference		operator[] (size_type n);
			const_reference	operator[] (size_type n) const;

			reference		at (size_type n);
			const_reference	at (size_type n) const;

			reference		front();
			const_reference	front() const;

			reference		back();
			const_reference	back() const;

			//// Modifiers
			template <class InputIterator>
			void			assign (InputIterator first, InputIterator last);

			void			assign (size_type n, const value_type& val);

			void			push_back (const value_type& val);

			void			pop_back();

			iterator		insert (iterator position, const value_type& val);

    		void			insert (iterator position, size_type n, const value_type& val);

			template <class InputIterator>
    		void			insert (iterator position, InputIterator first, InputIterator last);

			iterator		erase (iterator position);

			iterator		erase (iterator first, iterator last);

			void			swap (vector& x);
			
			void			clear();

			allocator_type	get_allocator() const;

			// void resize(size_t n, const T& value = T())
			// {
			// 	if (n > capacity) reserve(n);
			// 	for (size_t i = size; i < n; ++i)
			// 	{
			// 		arr[i] = value;
			// 	}
			// 	if (n < size)
			// 		size = n;
			// }


			// void push_back(const T& value)
			// {
			// 	if (capacity == size)
			// 		reserve(2 * size);			
			// 	arr[size] = value;
			// 	++size;
			// }

			// void pop_back()
			// {
			// 	--size;
			// }

			// Non-member function overloads
			template <class T, class Alloc>
			friend bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			template <class T, class Alloc>
			friend bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			template <class T, class Alloc>
			friend bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			template <class T, class Alloc>
			friend bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			template <class T, class Alloc>
			friend bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

			template <class T, class Alloc>
			friend bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
			
			template <class T, class Alloc>
  			friend void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);

		private:
			allocator_type	_allocator;
			size_type		_capacity;
			pointer			_ptr;
			size_type		_size;
	};
}

#endif