/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aptive <aptive@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:06:51 by aptive            #+#    #+#             */
/*   Updated: 2023/01/30 16:09:11 by aptive           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_utils.hpp"
#include <vector>
#include <algorithm>    // std::equal

#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define END "\033[0m"


bool mypredicate (int i, int j) {
	return (i==j);
}

int main()
{

	std::cout << "+----------------------------------------------------------------+" << std::endl;
	std::cout << "|                        TEST FT_UTILS                           |" << std::endl;
	std::cout << "+----------------------------------------------------------------+" << std::endl;

	std::cout << "|************************** TEST PAIR ***************************|" << std::endl;

	// Test Make_pair ---------------------------------------------------------------------
		ft::pair <std::string,double> product1_ft;                     // default constructor
		std::pair <std::string,double> product1;                     // default constructor

		product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
		product1_ft = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

		if (product1.first == product1_ft.first && product1.second == product1_ft.second)
			std::cout << GREEN << "	Test Make_pair :				OK" << END << std::endl;
		else
			std::cout << RED << "	Test Make_pair :				Not OK" << END << std::endl;

	// Test initialisation ----------------------------------------------------------------
		ft::pair <std::string,double> product2_ft ("tomatoes",2.30);   // value init
		std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init

		if (product2_ft.first == product2.first && product2_ft.second == product2.second)
			std::cout << GREEN << "	Test initialisation :				OK" << END << std::endl;
		else
			std::cout << RED << "	Test initialisation :				Not OK" << END << std::endl;

	// Test copy --------------------------------------------------------------------------
		ft::pair <std::string,double> product3_ft (product2_ft);          // copy constructor
		std::pair <std::string,double> product3 (product2);          // copy constructor

		if (product3_ft.first == product3.first && product3_ft.second == product3.second)
			std::cout << GREEN << "	Test copy :					OK" << END << std::endl;
		else
			std::cout << RED << "	Test copy :					KO" << END << std::endl;
	// Test operator = attribut -----------------------------------------------------------

		product3.first = "shoes";                  // the type of first is string
		product3_ft.first = "shoes";                  // the type of first is string
		product3.second = 39.90;                   // the type of second is double
		product3_ft.second = 39.90;                   // the type of second is double

		if (product3_ft.first == product3.first && product3_ft.second == product3.second)
			std::cout << GREEN << "	Test operator = direct attribut :		OK" << END << std::endl;
		else
			std::cout << RED << "	Test operator = direct attribut :		KO" << END << std::endl;

	// Test operator = attribut -----------------------------------------------------------
		ft::pair <std::string,double> product4_ft = product2_ft;          // copy constructor
		if (product2_ft.first == product4_ft.first && product2_ft.second == product4_ft.second)
			std::cout << GREEN << "	Test operator = attribut :			OK" << END << std::endl;
		else
			std::cout << RED << "	Test operator = attribut :			KO" << END << std::endl;

	std::cout << std::endl;








	std::cout << "|************************** TEST EQUAL **************************|" << std::endl;

	int myints[] = {20,40,60,80,100};               //   myints: 20 40 60 80 100
	std::vector<int>myvector (myints,myints+5);     // myvector: 20 40 60 80 100

	// using default comparison------------------------------------------------------------
	if ( std::equal (myvector.begin(), myvector.end(), myints)
		&& ft::equal (myvector.begin(), myvector.end(), myints))
		std::cout << GREEN <<"	Test default comparaison :			OK\n" << END;
	else
		std::cout << RED <<"	Test default comparaison :			KO\n" << END;

	// using predicate comparison flase ---------------------------------------------------
	myvector[3]=81;                                 // myvector: 20 40 60 81 100
	if ( std::equal (myvector.begin(), myvector.end(), myints, mypredicate)
		&& ft::equal (myvector.begin(), myvector.end(), myints, mypredicate))
		std::cout << RED <<"	Test Predicate :				KO\n" << END;
	else
		std::cout << GREEN <<"	Test Predicate :				OK\n" << END;



	std::cout << std::endl;
	std::cout << "|************************* IS_INTEGRAL **************************|" << std::endl;

	if (ft::is_integral<char>::value)
		std::cout << GREEN <<"	Test Char :					OK\n" << END;
	else
		std::cout << RED <<"	Test Char :					KO\n" << END;

	if (ft::is_integral<int>::value)
		std::cout << GREEN <<"	Test int :					OK\n" << END;
	else
		std::cout << RED <<"	Test int :					KO\n" << END;

	if (!ft::is_integral<float>::value)
		std::cout << GREEN <<"	Test float :					OK\n" << END;
	else
		std::cout << RED <<"	Test float :					KO\n" << END;

	if (!ft::is_integral<double>::value)
		std::cout << GREEN <<"	Test double :					OK\n" << END;
	else
		std::cout << RED <<"	Test double :					KO\n" << END;



	std::cout << std::endl;
	std::cout << "|************************* ENABLE IF ****************************|" << std::endl;


	short int i = 1;    // code does not compile if type of i is not integral

	if (ft::is_odd(i))
		std::cout << GREEN <<"	Test enable if :				OK\n" << END;
	else
		std::cout << RED <<"	Test double :					KO\n" << END;

	std::cout << std::endl;
	std::cout << "+----------------------------------------------------------------+" << std::endl;
	std::cout << "|                        END FT_UTILS                            |" << std::endl;
	std::cout << "+----------------------------------------------------------------+" << std::endl;











  return 0;
}

