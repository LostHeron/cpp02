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
	Point a(0,0, "a");
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
}
