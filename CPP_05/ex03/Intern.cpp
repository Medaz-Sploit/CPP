/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:28:35 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 04:28:36 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	return ;
}

Intern::Intern(const Intern & src)
{
	*this = src;
	return ;
}

Intern::~Intern()
{
	return ;
}

Intern & Intern::operator=(Intern const & rhs)
{
	(void)rhs;
	return *this;
}

static Form*	robotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

static Form*	shrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static Form*	presidential(std::string target)
{
	return new PresidentialPardonForm(target);
}

Form* 			Intern::makeForm(std::string formName, std::string formTarget)
{
	Form*		(*form[QT_FORMS])(std::string target) = {
		&presidential,
		&shrubbery,
		&robotomy
	};
	std::string	formsCmp[QT_FORMS] = {
		"presidential request",
		"shrubbery request",
		"robotomy request"
	};

	try
	{
		for (int i = 0; i < QT_FORMS; i++)
		{
			if (formName == formsCmp[i])
			{
				std::cout << "Intern create form : " << formName << std::endl;
				return form[i](formTarget);
			}
		}
		throw InternException();

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return NULL;
	}
}

const char* Intern::InternException::what() const throw()
{
	return ("Intern makes an error...");
}