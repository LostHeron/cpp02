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

Fixed	cross_product_z(const Point& a, const Point& b);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	
	Fixed cross1 = cross_product_z(Point(b - a), Point(point - a));
	Fixed cross2 = cross_product_z(Point(c - b), Point(point - b));
	Fixed cross3 = cross_product_z(Point(a - c), Point(point - c));
	//int	sign2
	//int	sign3
	if ((cross1 >= 0 && cross2 >= 0 && cross3 >= 0)
		|| (cross1 < 0 && cross2 < 0 && cross3 < 0))
		return (true);
	return (false);
}

Fixed	cross_product_z(const Point& a, const Point& b)
{
	return (Fixed(a.getX() * b.getX() + a.getY() * b.getY()));
}
