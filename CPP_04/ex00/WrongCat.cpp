/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:17:26 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 00:18:07 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "Create " << this->type << std::endl;
	return ;
}

WrongCat::WrongCat( const WrongCat & src )
{
	*this = src;
	std::cout << "Create from copy " << this->type << std::endl;
	return ;
}

WrongCat::~WrongCat( void )
{
	std::cout << "Destroye " << this->type << std::endl;
	return ;
}

WrongCat &				WrongCat::operator=( WrongCat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.type;
	}
	return *this;
}

void	WrongCat::makeSound( void ) const
{
	std::cout << "Miaou !" << std::endl;
}