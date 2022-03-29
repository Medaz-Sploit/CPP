/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:10:03 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 13:22:22 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << this->_type << " Created." << std::endl;
	return;
}

Cat::Cat(Cat const & rhs)
{
	*this = rhs;
	std::cout << "Created copy contructor from " << this->_type << std::endl;
	return;
}

Cat::~Cat()
{
	std::cout << this->_type << " Rest in peace meow" << std::endl;
	return;
}

Cat & Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Meeeeeowww Meeeeeowww Meow.." << std::endl;
	return;
}

std::ostream & operator<<(std::ostream & o, Cat const & i)
{
	o << i.getType();
	return o;
}