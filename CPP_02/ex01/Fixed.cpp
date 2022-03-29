/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 15:06:44 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/27 15:32:18 by mazoukni         ###   ########.fr       */
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