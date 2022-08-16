#ifndef ITERATOR_TAGS_HPP
#define ITERATOR_TAGS_HPP

namespace ft
{
	class input_iterator_tag{};
	class output_iterator_tag{};
	class forward_iterator_tag{};
	class bidirectional_iterator_tag{};
	class random_access_iterator_tag{};

	template <bool val, typename T>
	struct is_iterator_tag
	{
		typedef T type;
		static const bool value = val;
	};

	template<typename T>
	struct is_input_iterator_tag: public is_iterator_tag<false, T>{};

	template<>
	struct is_input_iterator_tag<input_iterator_tag>: public is_iterator_tag<true, input_iterator_tag>{};

	template<>
	struct is_input_iterator_tag<forward_iterator_tag>: public is_iterator_tag<true, forward_iterator_tag>{};

	template<>
	struct is_input_iterator_tag<bidirectional_iterator_tag>: public is_iterator_tag<true, bidirectional_iterator_tag>{};

	template<>
	struct is_input_iterator_tag<random_access_iterator_tag>: public is_iterator_tag<true, random_access_iterator_tag>{};

	template<typename T>
	struct is_random_access_iterator_tag: public is_iterator_tag<false, T>{};

	template<>
	struct is_random_access_iterator_tag<random_access_iterator_tag>: public is_iterator_tag<true, random_access_iterator_tag>{};
}

#endif