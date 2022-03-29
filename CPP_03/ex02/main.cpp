/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:03:37 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 07:24:54 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
     std::cout << std::endl << "FragTrap tests" << std::endl << std::endl;
    FragTrap    f0;
    FragTrap    f1("F1");

    f0.highFivesGuys();
    // f0.guardGate(); // can't compile
    f1.attack("a chicken");
    
    FragTrap    fcopy(f1);
    fcopy.attack("pouet");
    fcopy.attack("pouet");

    std::cout << std::endl <<  "fcopy ";

    ScavTrap    s1("Scavvvvv");
    s1.guardGate();
}