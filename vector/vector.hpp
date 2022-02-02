#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

template < class T, class Alloc = std::allocator<T> >
class vector
{
	T *arr;
	size_t size;
	size_t capacity;

	void reserve(size_t n)
	{
		if (n < capacity) return ;
		T* newarr = new T[n];
		for (size_t i = 0; i < size; ++i)
		{
			newarr[i] = arr[i];
		}
		delete[] arr;
		arr = newarr;
		capacity = n;
	}

	void resize(size_t n, const T& value = T())
	{
		if (n > capacity) reserve(n);
		for (size_t i = size; i < n; ++i)
		{
			arr[i] = value;
		}
		if (n < size)
			size = n;
	}


	void push_back(const T& value)
	{
		if (capacity == size)
			reserve(2 * size);			
		arr[size] = value;
		++size;
	}

	void pop_back()
	{
		--size;
	}
};

#endif