/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 21:44:07 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/24 01:51:56 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.class.hpp"
#include "Zombie.hpp"

int main(void)
{
	int N = 20;
	std::string vampire = "Dargola";
	Zombie* immortal = zombieHorde(N, vampire);

	for (int i = 0; i < N; i++)
		immortal[i].announce();
	delete [] immortal;
	return (0);
}