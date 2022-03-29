/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:16:30 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 07:02:22 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
	std::cout << "ScavTrap " << this->_name << " has awaken." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << this->_name << " has created." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	return;
}

ScavTrap::ScavTrap(ScavTrap const & rhs) : ClapTrap(rhs.getName())
{
	*this = rhs;
	std::cout << "Create ScavTrap from copy : " << this->_name << std::endl;
	return;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " rest in peace." << std::endl;
	return;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		this->_hitPoints = rhs.getHitPoints();
		this->_energyPoints = rhs.getEnergyPoints();
		this->_attackDamage = rhs.getAttackDamage();
	}
	return *this;
}

void ScavTrap::guardGate(void)
{
	if (!this->canPlay())
		return;
	std::cout << this->ClapTrap::_name << " change to Gate keeper mode." << std::endl;
    return ;
}

void ScavTrap::attack(const std::string & target)
{
	if (!this->canPlay())
		return;
	this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " attacks " << target;
    std::cout << " causing " << this->_attackDamage << " points of damage !" << std::endl;
    return ;
}