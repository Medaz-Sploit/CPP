/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:37:30 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 04:37:31 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_H
#define SERIALIZE_H

#include <iostream>
#include <stdint.h>

typedef struct 	s_Data {
	int			a;
	char		b;
}				Data;

uintptr_t		serialize(Data* ptr);
Data*			deserialize(uintptr_t raw);

#endif