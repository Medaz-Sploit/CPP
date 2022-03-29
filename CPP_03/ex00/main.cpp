/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:03:37 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/27 17:03:56 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void )
{
    ClapTrap roger("roger");
    ClapTrap nope;
    ClapTrap roger2(roger);

    roger2.attack("Maurice");
    nope.attack("Marcel");

    std::cout << std::endl << roger.getHitPoints() << std::endl;
    roger.takeDamage(8);
    roger.beRepaired(2);
    std::cout << roger.getHitPoints() << std::endl;
    roger.attack("Pouet");
    for (int i = 0; i < 10; i++)
        roger.beRepaired(1);
    roger.takeDamage(10);
    roger.attack("Pouet");
    roger.takeDamage(10);
    roger.attack("sdflk");
}