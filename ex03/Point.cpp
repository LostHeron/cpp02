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
	name("NoName"),
	x(0, name + "_x"),
	y(0, name + "_y")
{
	std::cout << "Point '"
		<< this->name << "' default constructor called" << std::endl;
}

Point::Point(const std::string& str):
	name(str),
	x(0, name + "_x"),
	y(0, name + "_y")
{
	std::cout << "Point '"
		<< this->name << "' default constructor called" << std::endl;
}

Point::Point(const float newX, const float newY):
	name("NoName"),
	x(newX, name + "_x"),
	y(newY, name + "_y")
{
	std::cout << "Point '"
		<< this->name << "' constructor with 2 floats called" << std::endl;
}

Point::Point(const float newX, const float newY, const std::string& newName):
	name(newName),
	x(newX, name + "_x"),
	y(newY, name + "_y")
{
	std::cout << "Point '"
		<< this->name << "' constructor with 2 floats, one name called" << std::endl;
}

Point::Point(const Fixed& newX, const Fixed& newY):
	name("NoName"),
	x(newX, name + "_x"),
	y(newY, name + "_y")
{
	std::cout << "Point '" << this->name <<
		"' constructor with 2 Fixed called" << std::endl;
}

Point::Point(const Fixed& newX, const Fixed& newY, const std::string& newName):
	name(newName),
	x(newX, name + "_x"),
	y(newY, name + "_y")
{
	std::cout << "Point '" << this->name <<
		"' constructor with 2 Fixed called, one name" << std::endl;
}

Point::Point(const Point& other):
	name(other.name + "_copy"),
	x(other.x, name + "_x"),
	y(other.y, name + "_y")
{
	std::cout << "Point '" << this->name
		<< "' copy constructor called using '" << other.name
		<< "' data !" << std::endl;
}

Point::Point(const Point& other, const std::string& newName):
	name(newName),
	x(other.x, name + "_x"),
	y(other.y, name + "_y")
{
	std::cout << "Point '" << this->name
		<< "' copy constructor called using '" << other.name
		<< "' data !" << std::endl;
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
	std::cout << "Point '" << this->name 
		<< "'desctructor called" << std::endl;
}

const Fixed& Point::getX() const
{
	return (this->x);
}

const Fixed& Point::getY() const
{
	return (this->y);
}

const std::string& Point::getName() const
{
	return (this->name);
}

Point operator-(const Point& p1, const Point& p2)
{
	std::cout << "in Point operator '-'" << std::endl;
	Fixed	newX(p1.getX() - p2.getX(), "newX");
	std::cout << newX << std::endl;
	Fixed	newY(p1.getY() - p2.getY(), "newY");
	std::cout << newY << std::endl;
	std::cout << "creating new point :" << std::endl;
	return (Point(newX, newY, p1.getName() + " - " + p2.getName()));
}

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "\nPoint '" << p.getName() << "':\n"
		"x:" << p.getX() << "\n"
		"y:" << p.getY() << "\n" << std::endl;
	return (os);
}
