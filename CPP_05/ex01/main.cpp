/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 00:59:35 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 00:28:41 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {

	Bureaucrat	hermes("Hermes", 52);
	Bureaucrat	Roger("Roger", 150);
	Form		basic;

	std::cout << basic << std::endl;
	basic.beSigned(hermes);
	std::cout << basic << std::endl;


	std::cout << "------------------------" << std::endl << std::endl;


	Form		lp("Laissez passer A38", 100, 90);

	std::cout << lp << std::endl;
	try
	{
		lp.beSigned(Roger);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << std::endl << "Roger try to sign lp (erreur attendu)" << std::endl;
	Roger.signForm(lp);
	std::cout << std::endl << lp << std::endl;
	
	std::cout << "Hermes try to sign lp" << std::endl;
	hermes.signForm(lp);
	std::cout << lp << std::endl;
	hermes.signForm(lp);
	return 0;
}