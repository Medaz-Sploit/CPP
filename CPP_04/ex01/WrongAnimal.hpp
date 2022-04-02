/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:14:35 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 00:15:05 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string 		type;

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		~WrongAnimal( void );


		std::string			getType( void ) const;
		void				makeSound( void ) const;

		WrongAnimal &			operator=( WrongAnimal const & rhs );
};

#endif