/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:10:51 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 00:33:04 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		Bureaucrat(void);
		std::string	_name;
		short		_grade;
	public:
		Bureaucrat(std::string const);
		Bureaucrat(std::string const , short);
		Bureaucrat(Bureaucrat const & rhs);
		~Bureaucrat();
		Bureaucrat & operator=(Bureaucrat const & rhs);

		void	checkGrade(void);
		void	promotion(void);
		void	retrograde(void);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		std::string const getName(void) const;
		short		getGrade(void) const;
};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);

#endif