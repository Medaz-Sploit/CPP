/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:53:52 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 01:54:49 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationFormTest", SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target("Test")
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) :
			Form("ShrubberyCreationFormCopy-" + src.getTarget(), SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target(src.getTarget())
{
	*this = src;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) :
			Form("ShrubberyCreationForm-" + target, SHRUBBERY_SIGN, SHRUBBERY_EXEC), _target(target)
{
	return ;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return ;
}

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		this->_target = rhs.getTarget();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "ShrubberyCreationForm : " << i.getTarget();
	return o;
}

std::string			ShrubberyCreationForm::getTarget( void ) const
{
	return this->_target;
}

void				ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
{
	try
	{
		this->checkExecution(executor);
	}
	catch(const std::exception& e)
	{
		throw	e.what();
	}
	std::string		output_name = this->getTarget() + "_shrubbery";
	std::ifstream	input("Tree");
	std::ofstream	output(output_name.c_str());

	if (input.is_open() && output.is_open())
	{
		output << input.rdbuf() << "   "
			<< this->getTarget() << " Created by " << executor.getName();
		input.close();
		output.close();
		std::cout << output_name << " created" << std::endl;
	}
	else
		std::cerr << "Error while openning file." << std::endl;
}
