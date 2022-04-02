/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 00:08:13 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 01:44:33 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("PekhoKrat"), _grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string const name) : _name(name), _grade(150)
{
	return;
}

Bureaucrat::Bureaucrat(std::string const name, short grade) : _name(name), _grade(grade)
{
	try
	{
		this->checkGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

Bureaucrat::Bureaucrat(Bureaucrat const & rhs) : _name(rhs.getName()), _grade(rhs.getGrade())
{
	try
	{
		this->checkGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

Bureaucrat::~Bureaucrat()
{
	return;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
		this->_grade = rhs.getGrade();
	return *this;
}

void	Bureaucrat::checkGrade(void)
{
	if (this->getGrade() > 150)
		throw Bureaucrat::GradeTooLowException();
	if (this->getGrade() < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::promotion(void)
{
	try
	{
		this->_grade--;
		this->checkGrade();
		std::cout << this->getName() << " is promoted from grade " << (this->getGrade() + 1)
			<< " to grade " << this->getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		this->_grade++;
		std::cerr << this->getName() << " can't be promoted : " << e.what() << std::endl;
	}
	
}

void	Bureaucrat::retrograde(void)
{
	try
	{
		this->_grade++;
		this->checkGrade();
		std::cout << this->getName() << " is retrograded from grade " << (this->getGrade() - 1)
			<< " to grade " << this->getGrade() << std::endl;
		
	}
	catch(const std::exception& e)
	{
		this->_grade--;
		std::cerr << this->getName() << " can't be retrograded : " << e.what() << std::endl;
	}
	
}

std::string const Bureaucrat::getName(void) const
{
	return this->_name;
}

short		Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void					Bureaucrat::signForm( Form & f )
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed \"" << f.getName() << "\"" << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << this->getName() << " couldn't sign \"" << f.getName()
					<< "\" because " << e.what() << std::endl;
	}
	catch(const Form::AlreadySignForm& e)
	{
		std::cerr << this->getName() << " try to sign but " << e.what() << std::endl;
	}	
}

void					Bureaucrat::executeForm(Form const & f) const
{
	try
	{
		f.execute(*this);
	}
	catch(const char* e)
	{
		std::cerr << this->getName() << " failed to execute "
				<< f.getName() << " because : " << e << std::endl;
		return ;
	}
	std::cout << this->getName() << " executed " << f.getName() << std::endl;
	
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low exception");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High exception");
}