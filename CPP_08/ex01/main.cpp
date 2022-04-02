/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:06:09 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 05:06:23 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"
#include <map>
#include <vector>
#include <list>

void	subject_tests() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	try
	{
		sp.addNumber(3);
	}
	catch(const std::exception & e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

int	RandomNum () {
	return (std::rand());
}

void printEl(int i) {
	std::cout << i << std::endl;
}

int main() {
	std::srand(std::time(NULL));

	subject_tests();

	std::cout << std::endl << "----------------- Big Span -----------" << std::endl;
	Span				big(10000);
	std::vector<int>	vec(10000);

	std::generate(vec.begin(), vec.end(), RandomNum);
	// std::for_each(vec.begin(), vec.end(), printEl);

	big.addNumber(vec.begin(), vec.end());
	std::cout << big.shortestSpan() << std::endl;
	std::cout << big.longestSpan() << std::endl;


	std::cout << std::endl << "----------------- 0 Span -----------" << std::endl;
	Span	zero;

	try{zero.addNumber(345);}
	catch(const std::exception & e){
		std::cerr << e.what() << '\n';
	}
	try	{zero.shortestSpan();}
	catch(const char* e){
		std::cerr << e << '\n';
	}
	try{zero.longestSpan();}
	catch(const char* e){
		std::cerr << e << '\n';
	}
	
	std::cout << std::endl << "----------------- Range iterator too big -----------" << std::endl;
	Span				small(10);
	std::vector<int>	tooMuch(20);

	std::generate(tooMuch.begin(), tooMuch.end(), RandomNum);
	try
	{
		small.addNumber(tooMuch.begin(), tooMuch.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return 0;
}