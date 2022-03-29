/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:33:52 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/27 16:12:09 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _n(0)
{
	std::cout << "Default constructor called." << std::endl;
	return;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
	return;
}

Fixed::Fixed(Fixed const & rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = rhs;
}

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_n = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	return this->_n;
}

void Fixed::setRawBits(int const raw)
{
	if (raw)
		this->_n = raw;
	return;
}

Fixed::Fixed(const int itg) : _n(itg << fract_bits)
{
	std::cout << "Int constructor called" << std::endl;
	return;
}

Fixed::Fixed(const float flt) : _n(roundf(flt * (1 << this->fract_bits)))
{
	std::cout << "Float constructor called" << std::endl;
	return;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_n / (1 << this->fract_bits));
}

int Fixed::toInt(void) const
{
	return (this->_n >> fract_bits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.toFloat();
	return o;
}

bool Fixed::operator>(Fixed const & rhs) const
{
	return (this->getRawBits() > rhs.getRawBits()) ? true : false;
}

bool Fixed::operator<(Fixed const & rhs) const
{
	return (this->getRawBits() < rhs.getRawBits()) ? true : false;
}

bool Fixed::operator>=(Fixed const & rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits()) ? true : false;
}

bool Fixed::operator<=(Fixed const & rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits()) ? true : false;
}

bool Fixed::operator==(Fixed const & rhs) const
{
	return (this->getRawBits() == rhs.getRawBits()) ? true : false;
}

bool Fixed::operator!=(Fixed const & rhs) const
{
	return (this->getRawBits() != rhs.getRawBits()) ? true : false;
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	operator++();
	return old;
}

Fixed & Fixed::operator++()
{
	this->_n +=1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed old = *this;
	operator--();
	return old;
}

Fixed & Fixed::operator--()
{
	this->_n -= 1;
	return *this;
}

Fixed Fixed::operator+(Fixed const & rhs) const
{
	Fixed ret;
	ret.setRawBits(this->_n + rhs.getRawBits());
	return ret;
}

Fixed Fixed::operator-(Fixed const & rhs) const
{
	Fixed ret;
	ret.setRawBits(this->_n - rhs.getRawBits());
	return ret;
}

Fixed Fixed::operator/(Fixed const & rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

const Fixed & Fixed::min(Fixed const & f_point1, Fixed const & f_point2)
{
	return (f_point1 < f_point2) ? f_point1 : f_point2;
}

const Fixed & Fixed::max(Fixed const & f_point1, Fixed const & f_point2)
{
	return (f_point1 > f_point2) ? f_point1 : f_point2;
}

Fixed & Fixed::min(Fixed & f_point1, Fixed & f_point2)
{
	return (f_point1 < f_point2) ? f_point1 : f_point2;
}

Fixed & Fixed::max(Fixed & f_point1, Fixed & f_point2)
{
	return (f_point1 > f_point2) ? f_point1 : f_point2;
}