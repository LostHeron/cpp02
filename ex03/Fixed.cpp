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
#include <cmath>
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
	std::cout << "Fixed '" << this->name << "' constructor with name only called"
		<< std::endl;	
}

Fixed::Fixed(const Fixed& other): value(other.value), name(other.name + "_copy")
{
	std::cout << "Fixed '" << this->name << "' copy constructor called using '"
		<< other.name << "' data !"
		<< std::endl;
}

Fixed::Fixed(const Fixed& other, const std::string& newName):
	value(other.value),
	name(newName)
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

void	Fixed::showBits(void) const
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

// comparison operator overload

bool operator<(const Fixed& left, const Fixed &right)
{
	return (left.getRawBits() < right.getRawBits());
}

bool operator>(const Fixed& left, const Fixed &right)
{
	return (left.getRawBits() > right.getRawBits());
}

bool operator>=(const Fixed& left, const Fixed &right)
{
	return (left.getRawBits() >= right.getRawBits());
}

bool operator<=(const Fixed& left, const Fixed &right)
{
	return (left.getRawBits() <= right.getRawBits());
}

bool operator==(const Fixed& left, const Fixed &right)
{
	return (left.getRawBits() == right.getRawBits());
}

bool operator!=(const Fixed& left, const Fixed &right)
{
	return (left.getRawBits() != right.getRawBits());
}

// Operation operator overload

Fixed	operator+(const Fixed& left, const Fixed& right)
{
	Fixed a(left.getName() + " + " + right.getName());
	a.setRawBits(left.getRawBits() + right.getRawBits());
	return (a);
}

Fixed	operator-(const Fixed& left, const Fixed& right)
{
	std::cout << "in fixed operator '-'" << std::endl;
	Fixed a(left.getName() + " - " + right.getName());
	a.setRawBits(left.getRawBits() - right.getRawBits());
	return (a);
}

Fixed	operator*(const Fixed& left, const Fixed& right)
{
	std::cout << "in Fixed operator '*', getting '" << left.getName()
		<< "' * '" << right.getName() << "'" << std::endl;
	long long a = (long long) left.getRawBits() * right.getRawBits();
	a = a / (1 << Fixed::getFractionalBits());
	Fixed ret("operator*");
	ret.setRawBits(a);
	//ret.showBits();
	return (ret);
}

Fixed	operator/(const Fixed& left, const Fixed& right)
{
	return (Fixed((float)left.getRawBits() / right.getRawBits(), "operator/"));
}

int	Fixed::getFractionalBits()
{
	return (Fixed::fractionalBits);
}

// prefix increment (++Fixed)
Fixed&	Fixed::operator++()
{
	this->value++;
	return (*this);
}

// postfix increment (Fixed++);
Fixed	Fixed::operator++(int)
{
	Fixed old(*this);
	this->value++;
	return (old);
}

//prefix decrement (--Fixed)
Fixed&	Fixed::operator--()
{
	this->value--;
	return (*this);
}

//postfix decrement (Fixed--)
Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);
	this->value--;
	return (old);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	std::cout << "calling const Fixed::min" << std::endl;
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	std::cout << "calling const Fixed::max" << std::endl;
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	std::cout << "calling Fixed::min (no const)" << std::endl;
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	std::cout << "calling Fixed::max (no const)" << std::endl;
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

/*
static Fixed&	Fixed::min(const Fixed f1, const Fixed f2);
static Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2);
static Fixed&	Fixed::max(const Fixed f1, const Fixed f2);
*/
