/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:58:37 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 14:17:06 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void    make_list( const int qt_animals)
{
    std::cout << std::endl << "Creeons un tableau comme demande" << std::endl << std::endl;
    Animal*      list[qt_animals];

    for (int i = 0; i < qt_animals; i++)
    {
        std::cout << i << " : ";
        if (i % 2)
            list[i] = new Dog;
        else
            list[i] = new Cat();
    }
    std::cout << std::endl << "Sing !" << std::endl << std::endl;
    for (int i = 0; i < qt_animals; i++)
    {
        list[i]->makeSound();
    }
    std::cout << std::endl << std::endl << std::endl;
    for (int i = 0; i < qt_animals; i++)
    {
        std::cout << i << " : ";
        delete list[i];
    }
    std::cout << std::endl;
}


int main ( void )
{
    // Can't compile
    // AAnimal* pouet = new AAnimal();
    // AAnimal roger;

    make_list(10);

    std::cout << std::endl << "Can we access AAnimal sound ?" << std::endl;
    Animal* polo = new Dog();
    polo->Animal::makeSound();
    delete polo;

    return 0;
}