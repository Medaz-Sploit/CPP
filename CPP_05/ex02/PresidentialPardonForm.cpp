/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:46:53 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 01:48:18 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonFormTest", PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC), _target("Test robot")
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & src) :
			Form("PresidentialPardonFormCopy-" + src.getTarget(), PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC), _target(src.getTarget())
{
	*this = src;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
			Form("PresidentialPardonForm-" + target, PRESIDENTIAL_SIGN, PRESIDENTIAL_EXEC), _target(target)
{
	return ;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return ;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "PresidentialPardonForm : " << i.getTarget();
	return o;
}

std::string			PresidentialPardonForm::getTarget( void ) const
{
	return this->_target;
}

void				PresidentialPardonForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		this->checkExecution(executor);
	}
	catch(const std::exception& e)
	{
		throw	e.what();
	}
	std::cout << this->getTarget() << " was forgiven by Zafod Beeblebrox." << std::endl;
}