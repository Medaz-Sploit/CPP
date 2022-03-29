/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:11:55 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 13:21:47 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "a Brain Created with 100 Ideas." << std::endl;
	return;
}

Brain::Brain(Brain const & rhs)
{
	*this = rhs;
	std::cout << "Creat copy Brain with 100 ideas." << std::endl;
	return;
}

Brain::~Brain()
{
	std::cout << "The Brain melted eww!" << std::endl;
	return;
}
Brain & Brain::operator=(Brain const & rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = rhs.ideas[i];
	}
	return *this;
}