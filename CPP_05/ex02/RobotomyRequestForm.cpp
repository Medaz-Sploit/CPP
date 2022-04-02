/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:50:11 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 01:51:58 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestFormTest", ROBOTOMY_SIGNE, ROBOTOMY_EXEC), _target("Test robot")
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) :
			Form("RobotomyRequestFormCopy-" + src.getTarget(), ROBOTOMY_SIGNE, ROBOTOMY_EXEC), _target(src.getTarget())
{
	*this = src;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :
			Form("RobotomyRequestForm-" + target, ROBOTOMY_SIGNE, ROBOTOMY_EXEC), _target(target)
{
	return ;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return ;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & i)
{
	o << "RobotomyRequestForm : " << i.getTarget();
	return o;
}

std::string			RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void				RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		this->checkExecution(executor);
	}
	catch(const std::exception& e)
	{
		throw	e.what();
	}
	std::srand(time(NULL));
	std::cout << "[Drill noises]" << std::endl;
	if (std::rand() % 2 == 1)
		std::cout << "Robotomy on " << this->getTarget() << " worked !" << std::endl;
	else
		std::cout << "Robotomy on " << this->getTarget() << " failed !" << std::endl;
}