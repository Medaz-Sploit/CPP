/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 00:36:04 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/24 01:50:22 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie* Hordes = new Zombie[N];
	for (int i = 0; i < N; i++)
		Hordes[i].setName(name);
	return (Hordes);
}