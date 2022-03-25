/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:43:14 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/24 01:51:24 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"


void Zombie::setName(std::string name)
{
	this->_name = name;
}

Zombie::Zombie() : _name("Eren")
{
	std::cout << BOLDYELLOW << this->_name << " Zombie has born." << std::endl << RESET;
	return;
}

Zombie::~Zombie()
{
	std::cout << BOLDRED << this->_name << " Zombie has died." << std::endl << RESET;
	return;
}

void Zombie::announce(void) const
{
	std::cout << BOLDGREEN << this->_name << BOLDWHITE << ": BraiiiiiiinnnzzzZ..." << std::endl << RESET;
}

