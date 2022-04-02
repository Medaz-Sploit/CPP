/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 03:59:03 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 03:59:43 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main () {
	Bureaucrat	boss("Boss", 1);
	Intern		random;
	Form*		oneJob;

	oneJob = random.makeForm("robotomy request", "roger");
	
	std::cout << std::endl << std::endl << "------- Presidential Pardon -------" << std::endl;
	oneJob = random.makeForm("presidential request", "Roger");
	boss.signForm(*oneJob);
	boss.executeForm(*oneJob);
	delete oneJob;

	std::cout << std::endl << std::endl << "------- Robotomy request -------" << std::endl;
	oneJob = random.makeForm("robotomy request", "Roger");
	boss.signForm(*oneJob);
	boss.executeForm(*oneJob);
	delete oneJob;

	std::cout << std::endl << std::endl << "------- Shrubbery request -------" << std::endl;
	oneJob = random.makeForm("shrubbery request", "Roger");
	boss.signForm(*oneJob);
	boss.executeForm(*oneJob);
	delete oneJob;

	return 0;
}