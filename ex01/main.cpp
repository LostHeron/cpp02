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

	NL;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	NL;

	{
	Fixed fixed_float((float)1.5, "fixed_float");
	std::cout << "fixed_float.toInt() = " << fixed_float.toInt() << std::endl;
	std::cout << fixed_float << std::endl;
	fixed_float.showBits();
	NL;
	fixed_float.setRawBits(255);
	fixed_float.showBits();
	std::cout << fixed_float << std::endl;
	NL;
	fixed_float.setRawBits(-2147483393);
	fixed_float.showBits();
	std::cout << fixed_float << std::endl;
	NL;
	fixed_float.setRawBits(-1);
	fixed_float.showBits();
	std::cout << fixed_float << std::endl;
	NL;
	}

	NL;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	NL;

	{
	Fixed fixed_int(15, "fixed_int");
	std::cout << "fixed_int.toInt() = " << fixed_int.toInt() << std::endl;
	std::cout << fixed_int << std::endl;
	fixed_int.showBits();
	NL;
	fixed_int.setRawBits(255);
	fixed_int.showBits();
	std::cout << fixed_int << std::endl;
	NL;
	fixed_int.setRawBits(-2147483393);
	fixed_int.showBits();
	std::cout << fixed_int << std::endl;
	NL;
	fixed_int.setRawBits(-1);
	fixed_int.showBits();
	std::cout << fixed_int << std::endl;
	NL;
	}

	NL;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	NL;

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

