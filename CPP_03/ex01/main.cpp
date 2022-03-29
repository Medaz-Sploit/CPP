/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:03:37 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 07:09:16 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
    ClapTrap roger("roger");
    ClapTrap nope;
    ClapTrap roger2(roger);
	
	ScavTrap levi("Levi");
    ScavTrap Noob;
    ScavTrap levi2(levi);

    roger2.attack("Maurice");
    levi2.attack("Titan");
    nope.attack("Marcel");
    Noob.attack("Beast");

    std::cout << std::endl << roger.getHitPoints() << std::endl;
    std::cout << std::endl << levi.getHitPoints() << std::endl;
    roger.takeDamage(8);
    levi.takeDamage(12);
    roger.beRepaired(2);
    levi.beRepaired(4);
    std::cout << roger.getHitPoints() << std::endl;
    std::cout << levi.getHitPoints() << std::endl;
    roger.attack("Pouet");
    levi.attack("Mikasa");
    for (int i = 0; i < 10; i++)
	{
        roger.beRepaired(1);
        levi.beRepaired(2);
	}
    roger.takeDamage(10);
    levi.takeDamage(7);
    roger.attack("Pouet");
    levi.attack("Eren");
    roger.takeDamage(10);
    levi.takeDamage(12);
    roger.attack("sdflk");
    levi.attack("Beast");
}