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

Fixed::Fixed(const int newValue): 
	value(newValue << fractionalBits),
	name("NoName")
{
	std::cout << "Fixed '" << this->name << "' constructor with Int "
		<< newValue << " called" << std::endl;	
}

Fixed::Fixed(const int newValue, const std::string& newName):
	value(newValue << fractionalBits),
	name(newName)
{
	std::cout << "Fixed '" << this->name << "' constructor with Int "
		<< newValue << " called" << std::endl;	
}
#include <cmath>

Fixed::Fixed(const float newValue):
	value(roundf(newValue * (float)(1 << fractionalBits))),
	name("NoName")
{
	std::cout << "Fixed '" << this->name << "' constructor with float "
		<< newValue << " called" << std::endl;	
}

Fixed::Fixed(const float newValue, const std::string& newName):
	value(roundf(newValue * (1 << fractionalBits))),
	name(newName)
{
	std::cout << "Fixed '" << this->name << "' constructor with float "
		<< newValue << " called" << std::endl;	
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
	std::cout << "changing '" << this->name << "' raw value from "
		<< this->value << " to raw value " << newValue << std::endl;
	this->value = newValue;
}

float	Fixed::toFloat(void) const
{
	float res;
	res = ((float)this->value) / (1 << fractionalBits);
	return (res);
}

int		Fixed::toInt(void)	const
{
	int	res;
	res = this->value >> fractionalBits;
	return (res);
}

void	Fixed::showBits(void)
{
	unsigned int	value_copy = this->value;
	std::string	str;

	// get a string containing 0 and 1 representing value
	// in reverse order
	for (int i = 0; i < 32; i++)
	{
		if (value_copy % 2 == 0)
			str += "0";
		else
			str += "1";
		value_copy /= 2;
	}
	// inversing the string
	for (size_t i = 0; i < str.size() / 2; i++)
	{
		char tmp;
		tmp = str[i];
		str[i] = str[str.size() - 1 - i];
		str[str.size() - 1 - i] = tmp;
	}
	std::cout << "Fixed '" << this->name << "' bits are : "
		<< str << std::endl;
	return ;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << "Fixed '" << fixed.getName() << "' value is "
		<< fixed.toFloat();
	return (os);

}

std::string	Fixed::getName(void) const
{
	return (this->name);
}
