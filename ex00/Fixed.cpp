/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:21:31 by jweber            #+#    #+#             */
/*   Updated: 2026/01/15 15:09:07 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <string>

Fixed::Fixed(): value(0), name("NoName")
{
	std::cout << "Fixed '" << this->name << "' default constructor called"
		<< std::endl;	
}

Fixed::Fixed(const std::string& newName): value(0), name(newName)
{
	std::cout << "Fixed '" << this->name << "' default constructor called"
		<< std::endl;	
}

Fixed::Fixed(const Fixed& other): value(other.value), name(other.name + "_copy")
{
	std::cout << "Fixed '" << this->name << "' copy constructor called using '"
		<< other.name << "' data !"
		<< std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Fixed '" << this->name 
		<< "' assignement overload called, using '" << other.name
		<< "' data !" << std::endl;
	if (this == &other)
		return (*this);
	this->value = other.value;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Fixed '" << this->name << "' destructor called"
		<< std::endl;
}


int		Fixed::getRawBits(void) const
{
	return (this->value);
}

void	Fixed::setRawBits(int newValue)
{
	std::cout << "changing '" << this->name << "' value from "
		<< this->value << " to " << newValue << std::endl;
	this->value = newValue;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << "Fixed '" << fixed.getName() << "' value is "
		<< fixed.getRawBits();
	return (os);

}

std::string	Fixed::getName(void) const
{
	return (this->name);
}
