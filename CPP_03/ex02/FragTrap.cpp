/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:15:30 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 07:21:51 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("FragNoob")
{
	std::cout << "FragTrap " << this->_name << " has awaken." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << this->_name << " has created." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return;
}

FragTrap::FragTrap(FragTrap const & rhs) : ClapTrap(rhs.getName())
{
	*this = rhs;
	std::cout << "Create FragTrap from copy : " << this->_name << std::endl;
	return;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " rest in peace." << std::endl;
	return;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
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

void FragTrap::attack(const std::string & target)
{
	if (!this->canPlay())
		return;
	this->_energyPoints--;
    std::cout << "FragTrap " << this->_name << " attacks " << target;
    std::cout << " causing " << this->_attackDamage << " points of damage !" << std::endl;
    return ;
}

void FragTrap::highFivesGuys(void)
{
	if (!this->canPlay())
		return;
	std::cout << this->_name << " : \"High Fives Guys !\"" << std::endl;
    return ;
}