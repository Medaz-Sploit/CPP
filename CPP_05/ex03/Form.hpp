/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 01:19:30 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 01:42:48 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FORM_HPP
#define FORM_HPP

# include <iostream>
# include <string>
#include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		short const			_signGrade;
		short const			_execGrade;
	public:
		Form(void);
		Form(std::string, short, short);
		Form(Form const & rhs);
		virtual ~Form();
		
		Form & operator=(Form const & rhs);

		std::string		getName(void) const;
		bool			getSigned(void) const;
		short			getSignGrade(void) const;
		short			getExecGrade(void) const;

		void			checkSignGrade(void) const;
		void			checkExecGrade(void) const;
		void			checkExecution(  Bureaucrat const & executor) const;
		virtual void	execute( Bureaucrat const & executor) const = 0;
		void			beSigned(Bureaucrat & bureaucrat);

		class	NotSignException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	AlreadySignForm : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif