/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:07:37 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 13:00:32 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const & rhs);
		virtual ~Cat();
		
		Cat & operator=(Cat const & rhs);
		virtual void makeSound(void) const;
};

std::ostream & operator<<(std::ostream & o, Cat const & i);
#endif