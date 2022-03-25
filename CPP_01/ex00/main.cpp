/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:44:07 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/23 23:14:37 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"
#include "Zombie.hpp"

int main(void)
{
	std::string human = "Adam";
	std::string vampire = "Dargola";

	randomChump(human);
	Zombie* immortal = newZombie(vampire);
	immortal->announce();
	delete immortal;
}