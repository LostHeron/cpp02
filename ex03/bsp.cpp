/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:04:18 by jweber            #+#    #+#             */
/*   Updated: 2026/01/19 15:56:33 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Fixed	cross_product_z(const Point& a, const Point& b);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << "\n\n----- first cross ----" << std::endl;
	Point b_minus_a(b - a, "b_minus_a");
	std::cout << b_minus_a << std::endl;

	Point p_minus_a(point - a, "p_minus_a");
	std::cout << p_minus_a << std::endl;

	Fixed cross1("cross1");
	cross1.setRawBits(cross_product_z(b_minus_a, p_minus_a).getRawBits());
	std::cout <<  cross1 << std::endl;
	std::cout << "----- end first -----\n\n" << std::endl;

	std::cout << "\n\n----- second cross ----" << std::endl;
	Fixed cross2 = cross_product_z(Point(c - b), Point(point - b));
	std::cout << cross2 << std::endl;
	std::cout << "----- end second -----\n\n" << std::endl;

	std::cout << "\n\n----- third cross ----" << std::endl;
	Fixed cross3 = cross_product_z(Point(a - c), Point(point - c));
	std::cout << cross3 << std::endl;
	std::cout << "----- end third -----\n\n" << std::endl;

	if ((cross1 > 0 && cross2 > 0 && cross3 > 0)
		|| (cross1 < 0 && cross2 < 0 && cross3 < 0))
		return (true);
	return (false);
	return (true);
}

Fixed	cross_product_z(const Point& a, const Point& b)
{
	return (Fixed(a.getX() * b.getY() - a.getY() * b.getX()));
}
