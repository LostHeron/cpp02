/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:23:25 by jweber            #+#    #+#             */
/*   Updated: 2026/01/19 16:02:35 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

#define NL std::cout << std::endl

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	{
	std::cout << "------ begin test point default constructor -----\n" << std::endl;
	Point	a;
	std::cout << a << std::endl;
	}
	std::cout << "\n------ end  -----\n\n\n" << std::endl;

	{
	std::cout << "------ begin test point 2 float constructor -----\n" << std::endl;
	Point	a(3.0f, 4.5f);
	std::cout << a << std::endl;
	}
	std::cout << "\n------ end -----\n\n\n" << std::endl;

	{
	std::cout << "------ begin test point name only constructor -----\n" << std::endl;
	Point	a("a");
	std::cout << a << std::endl;
	}
	std::cout << "\n------ end -----\n\n\n" << std::endl;

	{
	std::cout << "------ begin test point 2 floats and name constructor -----\n" << std::endl;
	Point	a(3.5, 4.7, "a");
	std::cout << a << std::endl;
	}
	std::cout << "\n------ end -----\n\n\n" << std::endl;


	{
	std::cout << "------ begin test point 2 Fixed constructor -----\n" << std::endl;
	Point	a(Fixed(3.2f, "tmpX"), Fixed(4.7f, "tmpY"), "a");
	std::cout << a << std::endl;
	}
	std::cout << "\n------ end -----\n\n\n" << std::endl;

	{
	std::cout << "------ begin test point copy constructor -----\n" << std::endl;
	Point a(4.2, 5.6, "a");
	Point b(a);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	}
	std::cout << "\n------ end -----\n\n\n" << std::endl;


	{
	std::cout << "------ begin test point assignement operator -----\n" << std::endl;
	Point a(4.2, 5.6, "a");
	Point b("b");
	
	b = a;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	}
	std::cout << "\n------ end -----\n\n\n" << std::endl;

	{
	std::cout << "------ begin test BSP -----\n" << std::endl;
	Point a(10, 10, "a");
	Point b(10, 0, "b");
	Point c(0, 10, "c");
	Point p(9, 5, "p");
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << p << std::endl;

	if (bsp(a, b, c, p) == true)
		std::cout << "--------->p is inside triangle abc" << std::endl;
	else
		std::cout << "--------->p is outside triangle abc" << std::endl;
	}
	std::cout << "\n------ end -----\n\n\n" << std::endl;
}
