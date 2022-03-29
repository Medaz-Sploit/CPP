/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:14:54 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 06:31:50 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap has awaken." << std::endl;
	return;
}
ClapTrap::ClapTrap(std::string name) :  _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " has awaken." << std::endl;
	return;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap rest in peace." << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap const & rhs)
{
	*this = rhs;
	std::cout << "ClapTrap Copy Created." << std::endl;
	return;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return *this;
}

bool ClapTrap::canPlay(void) const
{
	if (this->_hitPoints <= 0)
	{
		std::cout << this->_name << " Can't play hit points(" << this->_hitPoints << ")" << std::endl;
		return (false);
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << this->_name << " Can't play energy points(" << this->_energyPoints << ")" << std::endl;
		return (false);
	}
	return (true);
}

void ClapTrap::attack(const std::string & target)
{
	if (!this->canPlay())
		return;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_attackDamage << " damage!" << std::endl;
	return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->canPlay())
		return;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " restored his points he currently have " << this->_hitPoints << " hits points." << std::endl;
	return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage" << std::endl;
	if ((int)amount > (int)this->_hitPoints / 2)
		std::cout << "Please Repair soon or you can't play." << std::endl;
	return;
	
}

int ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

int ClapTrap::getAttackDamage(void) const
{
	return this->_attackDamage;
}

std::string ClapTrap::getName(void) const
{
	return this->_name;
}