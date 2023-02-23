/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:12:39 by aptive            #+#    #+#             */
/*   Updated: 2023/01/30 18:25:11 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_HPP
# define FT_VECTOR_HPP

# include <iostream>
# include <cstdlib>
# include "./ft_iterator.tpp"

namespace
{
	template < class T, class Alloc = std::allocator<T> >
	class vector // generic template
	{
		typedef T												value_type;
		typedef Alloc											allocator_type;
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference		const_reference;
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		// typedef typename ::			iterator;
		// typedef typename ::			const_iterator;
		// typedef typename ::			reverse_iterator;
		// typedef typename ::			const_reverse_iterator;

		// typedef typename iterator_traits<iterator>::difference_type			difference_type;

		typedef size_t 											size_type;
		public :
		//constructor

			// default (1)
			explicit vector (const allocator_type& alloc = allocator_type())
			{};
			// fill (2)
			explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type())
			{};
			// range (3)
			template <class InputIterator>vector (InputIterator first, InputIterator last,const allocator_type& alloc = allocator_type())
			{};
			// copy (4)
			vector (const vector& x)
			{};
			// operator = (4)
			vector& operator= (const vector& x)
			{};

		//destructor
			~vector()
			{};

		// Iterators:
			// begin // Return iterator to beginning
			iterator begin()
			{};
			const_iterator begin() const
			{};

			// end Return iterator to end
			iterator end()
			{};
			const_iterator end() const
			{};

			// rbegin Return reverse iterator to reverse beginning
			reverse_iterator rbegin()
			{};
			const_reverse_iterator rbegin() const
			{};

			// rend Return reverse iterator to reverse end
			reverse_iterator rend()
			{};
			const_reverse_iterator rend() const
			{};



			// Capacity:
			// size Return size
			size_type size() const
			{};

			// max_size Return maximum size
			size_type max_size() const
			{};

			// resize Change size
			void resize (size_type n, value_type val = value_type())
			{};

			// capacity Return size of allocated storage capacity
			size_type capacity() const
			{};

			// empty Test whether vector is empty
			bool empty() const
			{};

			// reserve Request a change in capacity
			void reserve (size_type n)
			{};

			// Element access:
			// operator[] Access element
			reference operator[] (size_type n);const_reference operator[] (size_type n) const
			{};

			// at Access element
			reference at (size_type n)
			{};
			const_reference at (size_type n) const
			{};

			// front Access first element
			reference front(){};
			const_reference front() const{};

			// back Access last element
			reference back(){};
			const_reference back() const{};


		// Modifiers:
			// assign Assign vector content
				// range (1)  the new contents are elements constructed from each of the elements in the range between first and last, in the same order.
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{};

				// fill (2) In the fill version (2), the new contents are n elements, each initialized to a copy of val.
			void assign (size_type n, const value_type& val)
			{};

			// push_back Add element at the end
			void push_back (const value_type& val)
			{};

			// pop_back Delete last element
			void pop_back(){};

			// insert Insert elements
			// single element (1)
			iterator insert (iterator position, const value_type& val){};
			// fill (2)
			void insert (iterator position, size_type n, const value_type& val){};
			// range (3)
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last){};

			// erase Erase elements
			iterator erase (iterator position){};
			iterator erase (iterator first, iterator last){};

			// swap Swap content
			void swap (vector& x){};

			// clear Clear content
			void clear();


		// Allocator:
			// get_allocator Get allocator
			allocator_type get_allocator() const{};

	};

	// :relational operators (vector)

	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return (lhs == rhs); };

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return (lhs != rhs); };

	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return (lhs < rhs); };

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return !(lhs > rhs); };

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{return (lhs > rhs); };

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return !(lhs<rhs); }

	// std::swap (vector)

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);


	// template < class T, class Alloc = allocator<T> > class vector;
	// generic templatetemplate <class Alloc> class vector<bool,Alloc>;               // bool specialization


};
#endif
