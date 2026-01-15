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
		Fixed(const std::string& newName);
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int newValue);

		std::string	getName(void) const;

	private:
		int					value;
		std::string			name;
		static const int	fractional_bits = 8;
};
		
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
