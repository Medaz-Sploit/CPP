/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 01:19:22 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 01:42:31 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(void) : _name("Form"), _signed(false), _signGrade(150), _execGrade(150)
{
	return;
}

Form::Form(std::string name, short signGrade, short execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	return;
}

Form::Form(Form const & rhs) :  _name(rhs.getName()), _signed(rhs.getSigned()), _signGrade(rhs.getSignGrade()), _execGrade(rhs.getExecGrade())
{
	try
	{
		this->checkExecGrade();
		this->checkSignGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}

Form::~Form()
{
	return;
}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	return *this;
}

std::string Form::getName(void) const
{
	return this->_name;
}

bool			Form::getSigned(void) const
{
	return this->_signed;
}

short	Form::getSignGrade(void) const
{
	return this->_signGrade;
}

short	Form::getExecGrade(void) const
{
	return this->_execGrade;
}

void			Form::checkSignGrade(void) const
{
	if (this->getSignGrade() > 150)
		throw Form::GradeTooLowException();
	if (this->getSignGrade() < 1)
		throw Form::GradeTooHighException();
}

void			Form::checkExecGrade(void) const
{
	if (this->getExecGrade() > 150)
		throw Form::GradeTooLowException();
	if (this->getExecGrade() < 1)
		throw Form::GradeTooHighException();
}

void					Form::checkExecution( Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw Form::NotSignException();
	if (executor.getGrade() >= this->getExecGrade())
		throw Form::GradeTooLowException();
	return ;
}

void			Form::beSigned(Bureaucrat & bureaucrat)
{
	if (this->getSigned())
		throw Form::AlreadySignForm();
	else if (bureaucrat.getGrade() <= this->getSignGrade())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Form const & i)
{
	o << "Form : " << i.getName() << std::endl << "Status : ";
	i.getSigned() ? o << "Signed" : o << "Unsigned";
	o << std::endl << "Min grade to sign : " << i.getSignGrade() << std::endl
	<< "Min grade to execute : " << i.getExecGrade() << std::endl;
	return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form : Grade too high exception");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form : Grade too low exception");
}

const char* Form::AlreadySignForm::what() const throw()
{
	return ("Form : already signed exception");
}

const char* Form::NotSignException::what() const throw()
{
	return ("AForm : not signed exception");
}