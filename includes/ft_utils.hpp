/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:57:53 by tdelauna          #+#    #+#             */
/*   Updated: 2023/01/28 17:33:20 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

• std::iterator_traits

• std::reverse_iterator

• std::enable_if

Yes, it is C++11 but you will be able to implement it in a C++98 manner.
This is asked so you can discover SFINAE.
• std::is_integral

• std::equal and/or std::lexicographical_compare

• std::pair

• std::make_pair




*/

#ifndef FT_UTILS_HPP
# define FT_UTILS_HPP

# include <iostream>
# include <string>


namespace ft
{
	// +---------------------------------------------------------------------------------+
	// |                                    PAIR                                         |
	// +---------------------------------------------------------------------------------+

	template <typename T1, typename T2>
	class pair
	{
		public:
		//Construteur par defaut
			pair( void ) {};
		//Construteur par copy
			// template<class U, class V>
			pair (const pair<T1,T2>& pr) : first(pr.first), second(pr.second) {};
		// Inialization
			pair (const T1 & a, const T2 & b) : first(a), second(b) {};
		// overload
			pair& operator=(const pair& pr){
				this->first = pr.first;
				this->second = pr.second;
				return *this;
			};
		// Destructeur
			~pair ( void ) {};

		// Methode
		public :
			T1	first;
			T2	second;
	};
	// Non-member function overloads ----------------------------------------------

	// elational operators (pair)	Relational operators for pair (function template)
	template <class T1, class T2>
		bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first==rhs.first && lhs.second==rhs.second; }

	template <class T1, class T2>
		bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs==rhs); }

	template <class T1, class T2>
		bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	template <class T1, class T2>
		bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(rhs<lhs); }

	template <class T1, class T2>
		bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return rhs<lhs; }

	template <class T1, class T2>
		bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{ return !(lhs<rhs); }

	// +---------------------------------------------------------------------------------+
	// |                                  END PAIR                                       |
	// +---------------------------------------------------------------------------------+



	// +---------------------------------------------------------------------------------+
	// |                                 MAKE PAIR                                       |
	// +---------------------------------------------------------------------------------+
	template <typename T1, typename T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		ft::pair<T1, T2> dest;

		dest.first = x;
		dest.second = y;

		return dest;
	}
	// +---------------------------------------------------------------------------------+
	// |                                   EQUAL                                         |
	// +---------------------------------------------------------------------------------+
		/*
		* Compare les éléments de la plage [first1,last1)avec ceux de la plage
		* commençant par first2 et renvoie true si tous
		* les éléments des deux plages correspondent.
		* Les éléments sont comparés à l'aide de operator==(ou pred , dans la version (2) ).
		*/

	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1!=last1)
		{
			if (!(*first1 == *first2))   // or: if (!pred(*first1,*first2)), for version 2
				return false;
			++first1; ++first2;
		}
		return true;
	};

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1!=last1)
		{
			if (!pred(*first1,*first2))
				return false;
			++first1; ++first2;
		}
		return true;
	};

	// +---------------------------------------------------------------------------------+
	// |                                 END EQUAL                                       |
	// +---------------------------------------------------------------------------------+

};

#endif
