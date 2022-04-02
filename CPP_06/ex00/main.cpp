/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:34:20 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 04:34:21 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstring>
#include "Literal.hpp"

void	checkBasics(int ac, char** av) {
	if (ac != 2)
		throw "Bad number of arguments";
	if (ac > 1)
		if (!strcmp(av[1], ""))
			throw "Argument is empty";
	return ;
}

int main( int ac, char** av) {
	try
	{
		checkBasics(ac, av);
	}
	catch(const char* e)
	{
		std::cerr << e << std::endl;
		return 0;
	}

	std::string		sav = static_cast<std::string>(av[1]);
	Literal			input(sav);

	input.printAll();
	std::cout << std::endl;
	return 0;
}