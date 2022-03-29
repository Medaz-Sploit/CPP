/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:52:15 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/27 14:58:04 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <string>

class Fixed
{
private:
	int _n;
	static const int fract_bits = 8;
public:
	Fixed();
	Fixed(Fixed const & rhs);
	~Fixed();

	Fixed & operator=(Fixed const & rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif