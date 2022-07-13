#ifndef STACK_HPP
# define STACK_HPP

# include <vector> // DONT FORGET TO REPLACE

namespace ft
{
	template <class T, class Container = std::vector<T> >
	class stack
	{
		public:
			// Member types
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;

			// Member methods
			explicit stack (const container_type& ctnr = container_type()) : _c(ctnr) {}

			~stack() {}

			bool				empty() const { return _c.empty(); }

			size_type			size() const { return _c.size(); }

			value_type&			top() { return _c.back(); }
			const value_type&	top() const { return _c.back(); }

			void				push (const value_type& val) { _c.push_back(val); }

			void				pop() { _c.pop_back(); }

			// Non-member function overloads
			template <class T, class Cont>
			friend bool			operator== (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs)
			{ return lhs._c == rhs._c; }

			template <class T, class Cont>
			friend bool			operator!= (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs)
			{ return lhs._c != rhs._c; }

			template <class T, class Cont>
			friend bool			operator<  (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs)
			{ return lhs._c < rhs._c; }

			template <class T, class Cont>
			friend bool			operator<= (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs)
			{ return lhs._c <= rhs._c; }

			template <class T, class Cont>
			friend bool			operator>  (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs)
			{ return lhs._c > rhs._c; }

			template <class T, class Cont>
			friend bool			operator>= (const stack<T,Cont>& lhs, const stack<T,Cont>& rhs)
			{ return lhs._c >= rhs._c; }
		
		private:
			container_type	_c;
	};
}


#endif