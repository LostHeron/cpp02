/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jweber <jweber@student.42Lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:08:49 by jweber            #+#    #+#             */
/*   Updated: 2026/01/19 15:53:30 by jweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Point_HPP
# define Point_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const std::string& str);
		Point(const float newX, const float newY);
		Point(const float newX, const float newY, const std::string& newName);
		Point(const Fixed& newX, const Fixed& newY);
		Point(const Fixed& newX, const Fixed& newY, const std::string& newName);
		Point(const Point& other);
		Point(const Point& other, const std::string& newName);
		Point&	operator=(const Point& left);
		~Point();

		const Fixed& getX() const;
		const Fixed& getY() const;
		//const Fixed& getName() const;
		const std::string& getName() const;

	private:
		std::string	name;
		Fixed const	x;
		Fixed const y;
};

Point operator-(const Point& p1, const Point& p2);

std::ostream& operator<<(std::ostream& os, const Point& p);

#endif
