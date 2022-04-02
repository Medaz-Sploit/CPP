/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 00:16:45 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 00:17:02 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_H
# define WRONGCAT_H

# include <iostream>
# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

	public:

		WrongCat( void );
		WrongCat( WrongCat const & src );
		~WrongCat( void );

		void		makeSound( void ) const;

		WrongCat &				operator=( WrongCat const & rhs );
		
};

std::ostream &			operator<<( std::ostream & o, WrongCat const & i );

#endif