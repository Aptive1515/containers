/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterator.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:20:38 by aptive            #+#    #+#             */
/*   Updated: 2023/01/30 19:53:15 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITERATOR_TPP
# define FT_ITERATOR_TPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <typeinfo>
#include <stddef.h>
#include <stdint.h>

namespace ft
{
	// +---------------------------------------------------------------------------------+
	// |                                    ITERATOR                                     |
	// +---------------------------------------------------------------------------------+
	template <class Iterator>
	class iterator_traits
	{
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
		typedef typename Iterator::iterator_category	iterator_category;
	};

	template <class T>
	class iterator_traits<T*>;

	template <class T>
	class iterator_traits<const T*>;

	// +---------------------------------------------------------------------------------+
	// |                               ITERATOR BASE CLASS                               |
	// +---------------------------------------------------------------------------------+

	// This is a base class template that can be used to derive iterator classes from it.
	// It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
	template <class Category, class T, class Distance = ptrdiff_t,class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	// +---------------------------------------------------------------------------------+
	// |                                BIDIRECTIONAL ITERATOR                           |
	// +---------------------------------------------------------------------------------+

	class random_access_iterator_tag { };

	template <typename T>
	class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
	{
		public :
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_category;
			/* Type of elements pointed. */
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
			/* Type to represent the difference between two iterators. */
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			/* Type to represent a pointer to an element pointed */
			typedef T*		pointer;
			/* Type to represent a reference to an element pointed */
			typedef T&		reference;


			// default-constructible
			random_access_iterator(T elem = NULL): _elem(elem){};
			// copy-constructible
			random_access_iterator(random_access_iterator<T> const & it){*this = it;};
			// copy-assignable
			random_access_iterator operator=(random_access_iterator<T> const & it){this->_elem = it._elem; return *this;};
			// destructible
			~random_access_iterator(){this->_elem = NULL;};
			/* Category of the iterator. */

		// BOOLEANS


			reference	operator*(){return *this->_elem;};
			pointer		operator->(){return this->_elem;};


			random_access_iterator &	operator++( void )
			{};
			random_access_iterator		operator++( int )
			{};
			// *a++

			random_access_iterator &	operator--( void )
			{};
			random_access_iterator		operator--( int )
			{};


			// ARITHMETICS
			random_access_iterator	operator+(random_access_iterator const & rhs)
			{};
			random_access_iterator	operator-(random_access_iterator const & rhs)
			{};


			//COMPOUND ASSIGNMENTS
			random_access_iterator operator+=(random_access_iterator const & rhs)
			{};
			random_access_iterator operator-=(random_access_iterator const & rhs)
			{};
			random_access_iterator operator[](random_access_iterator const & rhs)
			{};

		private:
				/* Element pointed by the iterator. */
			pointer _elem;

		public :
		// BOOLEANS
			friend bool operator==(const T & lhs, const T & rhs);
			friend bool operator!= (const T & lhs, const T & rhs);
			friend bool operator<(const T & lhs, const T & rhs);
			friend bool operator<=(const T & lhs, const T & rhs);
			friend bool operator>(const T & lhs, const T & rhs);
			friend bool operator>=(const T & lhs, const T & rhs);

	};

	template <class T >
	bool operator==(const T & lhs, const T & rhs)
	{return (lhs._elem == rhs._elem); };

	template <class T >
	bool operator!= (const T & lhs, const T & rhs)
	{return (lhs._elem != rhs._elem); };

	template <class T >
	bool operator<(const T & lhs, const T & rhs)
	{return (lhs._elem < rhs._elem); };

	template <class T >
	bool operator<=(const T & lhs, const T & rhs)
	{return !(lhs._elem > rhs._elem); };

	template <class T >
	bool operator>(const T & lhs, const T & rhs)
	{return (lhs._elem > rhs._elem); };

	template <class T >
	bool operator>=(const T & lhs, const T & rhs)
	{ return !(lhs._elem < rhs._elem); }

} // namespace name


#endif
