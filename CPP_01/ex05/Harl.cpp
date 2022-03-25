/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 01:14:44 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/25 11:56:25 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl has awaken." << std::endl;
	return;
}

Harl::~Harl()
{
	std::cout << "Harl rest in peace." << std::endl;
	return;
}

void Harl::_debug(void)
{
	std::cout << "DEBUG : I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do !" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "INFO : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "WARNING : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::_error(void)
{
	std::cout << "ERROR : This is unacceptable ! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*functPtr)(void);
	std::string  tab[TYPE] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	functPtr	funct[TYPE] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};

	for (int i = 0; i < TYPE; i++)
	{
		if (tab[i] == level)
			(this->*funct[i])();
	}
}
