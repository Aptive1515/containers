/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:57:53 by tdelauna          #+#    #+#             */
/*   Updated: 2023/01/27 14:43:06 by tdelauna         ###   ########.fr       */
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
	// ********************************** PAIR *******************************************
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
			// pair& operator=(const pair& pr){};

		// Destructeur
			~pair ( void ) {};

		// Methode
			// swap

		public :
			T1	first;
			T2	second;
	};
	// Non-member function overloads ----------------------------------------------

		// elational operators (pair)	Relational operators for pair (function template)
		// swap (pair)	Exchanges the contents of two pairs (function template)
		// get (pair)	Get element (tuple interface) (function template)



};

#endif
