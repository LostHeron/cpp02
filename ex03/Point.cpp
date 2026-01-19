/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:19:08 by jweber            #+#    #+#             */
/*   Updated: 2026/01/19 15:53:41 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Point.hpp"

Point::Point():
	x(Fixed(0)),
	y(Fixed(0))
{
	std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const Fixed& newX, const Fixed& newY):
	x(newX),
	y(newY)
{
	std::cout << "Point constructor with 2 Fixed called" << std::endl;
}

Point::Point(const Point& other):
	x(other.x),
	y(other.y)
{
	std::cout << "Point copy constructor called" << std::endl;
}

Point&	Point::operator=(const Point& other)
{
	(void) other;
	std::cout << "Point assignement operator called,"
	"but nothing happens since all attributes are const !" << std::endl;
	return (*this);
}

Point::~Point()
{
	std::cout << "Point desctructor called" << std::endl;
}

const Fixed& Point::getX() const
{
	return (this->x);
}

const Fixed& Point::getY() const
{
	return (this->y);
}

Point operator-(const Point& p1, const Point& p2)
{
	Fixed	newX = p1.getX() - p2.getX();
	Fixed	newY = p2.getY() - p2.getY();
	return (Point(newX, newY));
}
