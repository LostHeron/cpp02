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
		Point(const Fixed& newX, const Fixed& newY);
		Point(const Point& other);
		Point&	operator=(const Point& left);
		~Point();

		const Fixed& getX() const;
		const Fixed& getY() const;

	private:
		Fixed const	x;
		Fixed const y;
};

Point operator-(const Point& p1, const Point& p2);

#endif
