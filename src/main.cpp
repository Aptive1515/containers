/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdelauna <tdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:06:51 by aptive            #+#    #+#             */
/*   Updated: 2023/01/27 14:47:00 by tdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.hpp"

#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define END "\033[0m"


int main()
{

	std::cout << "----------------------------- TEST FT_UTILS --------------------------" << std::endl;

	std::cout << "----------------------------- TEST PAIR --------------------------" << std::endl;


		ft::pair <std::string,double> product1_ft;                     // default constructor
		std::pair <std::string,double> product1;                     // default constructor


		// product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
		product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
		// std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
		// std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';

		// std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';



		ft::pair <std::string,double> product2_ft ("tomatoes",2.30);   // value init
		std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init








		if (product2_ft.first == product2.first && product2_ft.second == product2.second)
			std::cout << GREEN << "Test initialisation : OK" << END << std::endl;
		else
			std::cout << RED << "Test initialisation : Not OK" << END << std::endl;





		ft::pair <std::string,double> product3_ft (product2_ft);          // copy constructor
		std::pair <std::string,double> product3 (product2);          // copy constructor

		// product2.first = "shoes";                  // the type of first is string

		if (product3_ft.first == product3.first && product3_ft.second == product3.second)
			std::cout << GREEN << "Test copy : OK" << END << std::endl;
		else
			std::cout << RED << "Test copy : Not OK" << END << std::endl;

		product3.first = "shoes";                  // the type of first is string
		product3_ft.first = "shoes";                  // the type of first is string
		product3.second = 39.90;                   // the type of second is double
		product3_ft.second = 39.90;                   // the type of second is double

		if (product3_ft.first == product3.first && product3_ft.second == product3.second)
			std::cout << GREEN << "Test operator = direct attribut : OK" << END << std::endl;
		else
			std::cout << RED << "Test operator = direct attribut : Not OK" << END << std::endl;

		std::cout << "----------------------------- END TEST PAIR --------------------------" << std::endl;











  return 0;
}

