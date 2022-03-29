/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:38:28 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 13:23:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type("Strange")
{
	std::cout << this->_type << " Animal constructor called." << std::endl;
	return;
}

Animal::Animal(Animal const & rhs)
{
	*this = rhs;
	std::cout << "Copy constructor created from " << this->_type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal " << this->_type << " destructor called." << std::endl;
}

Animal & Animal::operator=(Animal const & rhs)
{
	if (this != &rhs)
		this->_type = rhs._type;
	return *this;
}

void Animal::makeSound(void) const
{
	std::cout << "..." << std::endl;
	return;
}

std::string Animal::getType(void) const
{
	return this->_type;
}