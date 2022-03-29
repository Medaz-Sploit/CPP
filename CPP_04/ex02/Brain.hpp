/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:07:43 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/29 13:21:53 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
#define BRAIN_H

#include <string>
#include <iostream>

class Brain
{
	public:
		Brain();
		Brain(Brain const & rhs);
		~Brain();

		Brain & operator=(Brain const & rhs);

		std::string ideas[100];
};

#endif
