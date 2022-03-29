/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:47:16 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 13:00:44 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const & rhs);
		virtual ~Dog();
		Dog & operator=(Dog const & rhs);

		virtual void makeSound(void) const;
};

std::ostream & operator<<(std::ostream & o, Dog const & i);

#endif