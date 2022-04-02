/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:14:32 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 00:16:22 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknow WrongAnimal")
{
	std::cout << "Create WrongAnimal : " << this->type << std::endl;
	return ;
}

WrongAnimal::WrongAnimal( const WrongAnimal & src )
{
	*this = src;
	std::cout << "Create WrongAnimal from copy :" << this->type << std::endl;
	return ;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destroye WrongAnimal : " << this->type << std::endl;
	return ;
}

WrongAnimal &				WrongAnimal::operator=( WrongAnimal const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, WrongAnimal const & i )
{
	o << i.getType();
	return o;
}

void	WrongAnimal::makeSound( void ) const
{
	std::cout << "blorp" << std::endl;
}

std::string	WrongAnimal::getType( void ) const
{
	return (this->type);
}
