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
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {}

			~stack();

			bool				empty() const { return c.empty(); }

			size_type			size() const { return c.size(); }

			value_type&			top() { return c.back(); }
			const value_type&	top() const { return c.back(); }

			void				push (const value_type& val) { c.push_back(val); }

			void				pop() { c.pop_back(); }


			template <class T, class Container>
			friend bool			operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

			template <class T, class Container>
			friend bool			operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

			template <class T, class Container>
			friend bool			operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

			template <class T, class Container>
			friend bool			operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

			template <class T, class Container>
			friend bool			operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);

			template <class T, class Container>
			friend bool			operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
		private:
			container_type	c;
	};

	// Non-member function overloads
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c == rhs.c;
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return lhs.c != rhs.c;
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c < rhs.c; }

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c <= rhs.c; }

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c > rhs.c; }

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) { return lhs.c >= rhs.c; }
}


#endif