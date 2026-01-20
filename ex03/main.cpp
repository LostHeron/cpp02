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
	Point p(7, 7, "p");
	
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


	/*
	Point a(Fixed(0, "tmp_ax"), Fixed(0,"tmp_ay"), "a_0_0");
	std::cout << a << std::endl;
	*/
		 /*
	Point b(10, 0, "b");
	Point c(0, 10, "c");
	Point p1(2,2, "p1");
	Point p2(7,7, "p2");
	Point p3(0,0, "p3");

	if (bsp(a, b, c, p1) == true)
		std::cout << "\npoint p1 is INSIDE triangle" << std::endl;
	else
		std::cout << "\npoint p1 is OUTSIDE triangle" << std::endl;
	std::cout << std::endl;

	if (bsp(a, b, c, p2) == true)
		std::cout << "\npoint p2 is INSIDE triangle" << std::endl;
	else
		std::cout << "\npoint p2 is OUTSIDE triangle" << std::endl;
	std::cout << std::endl;

	if (bsp(a, b, c, p3) == true)
		std::cout << "\npoint p3 is INSIDE triangle" << std::endl;
	else
		std::cout << "\npoint p3 is OUTSIDE triangle" << std::endl;
	std::cout << std::endl;
	*/
}
