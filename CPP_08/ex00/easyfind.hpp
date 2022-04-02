/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:01:54 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 05:01:55 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template< typename T>
typename T::const_iterator	easyfind(T const & container, int const & toFind)
{
	typename T::const_iterator	it = std::find(container.begin(), container.end(), toFind);

	if (it == container.end())
		throw "Nothing";
	return (it);
}

#endif