/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:49:36 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 13:00:48 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << this->_type << " Created." << std::endl;
	return;
}

Dog::Dog(Dog const & rhs)
{
	*this = rhs;
	std::cout << "Created Copy contructor from " << this->_type << std::endl;
	return;
}

Dog::~Dog()
{
	std::cout << this->_type << " Died!" << std::endl;
	return;
}

Dog & Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
		this->_type = rhs.getType();
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Ouaf Ouaf !" << std::endl;
	return;
}

std::ostream & operator<<(std::ostream & o, Dog const & i)
{
	o << i.getType();
	return o;
}
