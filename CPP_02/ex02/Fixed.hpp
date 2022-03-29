/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:33:38 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/27 16:09:30 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int _n;
	static const int fract_bits = 8;
public:
	Fixed();
	Fixed(const int itg);
	Fixed(const float flt);
	Fixed(Fixed const & rhs);
	~Fixed();

	Fixed & operator=(Fixed const & rhs);

	bool operator>(Fixed const & rhs) const;
	bool operator<(Fixed const & rhs) const;
	bool operator>=(Fixed const & rhs) const;
	bool operator<=(Fixed const & rhs) const;
	bool operator==(Fixed const & rhs) const;
	bool operator!=(Fixed const & rhs) const;

	Fixed operator++(int);
	Fixed & operator++();
	Fixed operator--(int);
	Fixed & operator--();
	
	Fixed operator+(Fixed const & rhs) const;
	Fixed operator-(Fixed const & rhs) const;
	Fixed operator/(Fixed const & rhs) const;
	Fixed operator*(Fixed const & rhs) const;

	static Fixed & min(Fixed & f_point1, Fixed & f_point2);
	static const Fixed & min(Fixed const & f_point1, Fixed const & f_point2);
	static Fixed & max(Fixed & f_point1, Fixed & f_point2);
	static const Fixed & max(Fixed const & f_point1, Fixed const & f_point2);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif