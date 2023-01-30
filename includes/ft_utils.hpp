/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:57:53 by tdelauna          #+#    #+#             */
/*   Updated: 2023/01/30 15:57:00 by aptive           ###   ########.fr       */
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
# include <typeinfo>     // typeid


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
	// |                                 REMOVE_CV                                       |
	// +---------------------------------------------------------------------------------+

	template<class T>
	struct remove_cv{typedef T type;};

	template<class T>
	struct remove_cv<const T>{typedef T type;};

	template<class T>
	struct remove_cv<volatile T>{typedef T type;};

	template<class T>
	struct remove_cv<const volatile T>{typedef T type;};


	// +---------------------------------------------------------------------------------+
	// |                                IS_INTEGRAL                                      |
	// +---------------------------------------------------------------------------------+

	struct false_type {
		static const bool	value = false;
		operator bool() const { return value; };
	};

	struct true_type {
		static const bool	value = true;
		operator bool() const { return value; };
	};

	template <typename T> struct is_integral_base : ft::false_type {};
	template <> struct is_integral_base<bool> : ft::true_type {};
	template <> struct is_integral_base<char> : ft::true_type {};
	template <> struct is_integral_base<wchar_t> : ft::true_type {};
	template <> struct is_integral_base<short> : ft::true_type {};
	template <> struct is_integral_base<int> : ft::true_type {};
	template <> struct is_integral_base<long> : ft::true_type {};
	template <> struct is_integral_base<long long> : ft::true_type {};
	template <> struct is_integral_base<unsigned char> : ft::true_type {};
	template <> struct is_integral_base<unsigned short int> : ft::true_type {};
	template <> struct is_integral_base<unsigned int> : ft::true_type {};
	template <> struct is_integral_base<unsigned long int> : ft::true_type {};
	template <> struct is_integral_base<unsigned long long int> : ft::true_type {};

	template<typename T>
	struct is_integral : is_integral_base<typename ft::remove_cv<T>::type > {};


	// +---------------------------------------------------------------------------------+
	// |                                   ENABLE IF                                     |
	// +---------------------------------------------------------------------------------+

	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> { typedef T type; };

	// 1. the return type (bool) is only valid if T is an integral type:
	template <class T>
	typename ft::enable_if<ft::is_integral<T>::value,bool>::type
	is_odd (T i) {return bool(i%2);}

	// 2. the second template argument is only valid if T is an integral type:
	template <class T>
	typename ft::enable_if<ft::is_integral<T>::value,bool>::type
	is_even (T i) {return !bool(i%2);}


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

};

#endif
