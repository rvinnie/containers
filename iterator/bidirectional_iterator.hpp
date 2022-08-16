#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "../rb_tree/rb_tree.hpp"
#include "iterator_tags.hpp"

namespace ft 
{
	template <typename T>
	struct TreeNode;

	template<typename ValueType>
	class bidirectional_iterator
	{
	public:

		typedef ValueType						value_type;
		typedef ValueType*						pointer;
		typedef ValueType&						reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef ptrdiff_t						difference_type;

	private:	
		TreeNode<value_type>                        *_point;

	public:

		bidirectional_iterator() : _point(NULL) {}

		~bidirectional_iterator() {}

		explicit bidirectional_iterator(TreeNode<value_type> *point) 
		{
			_point = point;
		}

		bidirectional_iterator(bidirectional_iterator<ValueType> const &c) 
		{
			_point = c.base();
		}

		TreeNode<value_type> *base() const
		{
			return _point;
		}

		bidirectional_iterator &operator=(bidirectional_iterator<ValueType> const &c)
		{
			_point = c.base();
			return *this;
		}

		reference operator*() const
		{
			return *_point->value;
		}

		pointer operator->() const
		{
			return _point->value;
		}

		bidirectional_iterator operator++()
		{
			TreeNode<value_type> *p;

			if(_point->right)
			{
				_point = _point->right;
				while(_point->left)
					_point = _point->left;
			}
			else
			{
				p = _point->parent;
				while(p && _point == p->right)
				{
					_point = p;
					p = p->parent;
					
				}
				_point = _point->parent;		
			}
			return(*this);
		}

		const bidirectional_iterator operator++(int)
		{
			bidirectional_iterator it(*this);
			++(*this);
			return it;
		}

		bidirectional_iterator operator--()
		{
			TreeNode<value_type> *p;

			if(_point->left)
			{
				_point = _point->left;
				while(_point->right)
					_point = _point->right;
			}
			else
			{
				p = _point->parent;
				while(p && _point == p->left)
				{
					_point = p;
					p = p->parent;
				}
				_point = _point->parent;		
			}
			return(*this);
		}

		const bidirectional_iterator operator--(int)
		{
			bidirectional_iterator it(*this);
			--(*this);
			return (it);
		}
	};

	template<typename T>
	bool operator==(bidirectional_iterator<T> const &first, bidirectional_iterator<T> const &second)
	{
		return(first.base() == second.base());
	}

	template<typename T>
	bool operator!=(bidirectional_iterator<T> const &first, bidirectional_iterator<T> const &second)
	{
		return(first.base() != second.base());
	}
}

#endif