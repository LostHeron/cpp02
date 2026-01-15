/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:23:25 by jweber            #+#    #+#             */
/*   Updated: 2026/01/15 15:08:23 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

#define NL std::cout << std::endl

int	main(void)
{
	{
	// to show why should overload of equal operator return a Fixed
	// using assignement chain !
	Fixed fixed_default("fixed_default");
	NL;
	Fixed fixed_for_assign("fixed_for_assign");
	NL;
	Fixed fixed_for_assign_second("fixed_for_assign_second");
	NL;

	fixed_default.setRawBits(256);
	NL;

	std::cout << fixed_default << std::endl;
	std::cout << fixed_for_assign << std::endl;
	std::cout << fixed_for_assign_second << std::endl;
	NL;

	std::cout << "fixed_for_assign_second = fixed_for_assign = fixed_default;"
			<< std::endl;
	fixed_for_assign_second = fixed_for_assign = fixed_default;
	NL;

	std::cout << fixed_default << std::endl;
	std::cout << fixed_for_assign << std::endl;
	std::cout << fixed_for_assign_second << std::endl;
	NL;
	}

	NL;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	NL;

	{
	// to show possible method !
	Fixed fixed_default("fixed_default");
	NL;
	Fixed fixed_copy(fixed_default);
	NL;
	Fixed fixed_assign("fixed_assign");
	NL;

	std::cout << "(fixed_assign).operator=(fixed_default);" << std::endl;
	(fixed_assign).operator=(fixed_default);
	NL;

	std::cout << "fixed_assign = fixed_default;" << std::endl;
	fixed_assign = fixed_default;
	NL;

	std::cout << fixed_default << std::endl;
	std::cout << fixed_copy << std::endl;
	std::cout << fixed_assign<< std::endl;
	NL;
	}

	NL;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	NL;

	{
	// to test changing value using setRawBits(val);
	Fixed fixed_default("fixed_default");
	NL;
	fixed_default.setRawBits(2524);
	NL;
	Fixed fixed_copy(fixed_default);
	NL;
	Fixed fixed_assign("fixed_assign");
	NL;

	std::cout << "fixed_assign = fixed_default;" << std::endl;
	fixed_assign = fixed_default;
	NL;

	std::cout << fixed_default << std::endl;
	std::cout << fixed_copy << std::endl;
	std::cout << fixed_assign << std::endl;
	NL;
	}
}
