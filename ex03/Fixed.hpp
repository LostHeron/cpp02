/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:18:56 by jweber            #+#    #+#             */
/*   Updated: 2026/01/15 15:08:32 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <ostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int newValue);
		Fixed(const int newValue, const std::string& newName);
		Fixed(const float newValue);
		Fixed(const float newValue, const std::string& newName);
		Fixed(const std::string& newName);
		Fixed(const Fixed& other);
		Fixed(const Fixed& other, const std::string& newName);
		Fixed&	operator=(const Fixed& other);
		// prefix operator (++Fixed);
		Fixed&	operator++();
		// postfix operator (Fixed++)
		Fixed	operator++(int);
		// prefix decrement operator:
		Fixed&	operator--();
		// postfix decrement operator:
		Fixed	operator--(int);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int newValue);

		std::string	getName(void) const;

		float	toFloat(void) const;
		int		toInt(void)	const;

		void	showBits(void) const;

		static int	getFractionalBits();
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&	min(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);
		static Fixed&	max(Fixed& f1, Fixed& f2);

	private:
		int					value;
		std::string			name;
		static const int	fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

// comparison operator overload
bool	operator<(const Fixed& left, const Fixed &right);
bool	operator>(const Fixed& left, const Fixed &right);
bool	operator>=(const Fixed& left, const Fixed &right);
bool	operator<=(const Fixed& left, const Fixed &right);
bool	operator==(const Fixed& left, const Fixed &right);
bool	operator!=(const Fixed& left, const Fixed &right);

// operation operator overlaod
Fixed	operator+(const Fixed& left, const Fixed& right);
Fixed	operator-(const Fixed& left, const Fixed& right);
Fixed	operator/(const Fixed& left, const Fixed& right);
Fixed	operator*(const Fixed& left, const Fixed& right);

#endif
