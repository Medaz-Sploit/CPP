/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:34:23 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 14:15:10 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
	public:
		Animal();
		Animal(Animal const & rhs);
		virtual ~Animal();
	
		Animal & operator=(Animal const & rhs);
	
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
};

#endif