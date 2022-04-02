/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:53:27 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 04:53:28 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_H
#define ITER_H

#include <iostream>

template< typename T>
void	iter(T arr[], size_t const arrLength, void f(T const & arr)) {
	for (size_t i = 0; i < arrLength; i++)
	{
		f(arr[i]);
	}
}

#endif