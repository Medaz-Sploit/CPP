/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 07:12:51 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 07:15:15 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
# define FRAGTRAP_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(FragTrap const & rhs);
		~FragTrap();
		FragTrap & operator=(FragTrap const & rhs);

		void highFivesGuys(void);
		void attack(const std::string & target);
};

#endif