/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:28:40 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 04:28:41 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

#define QT_FORMS 3

class Intern
{
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern &		operator=(Intern const & rhs);

		Form*			makeForm(std::string formName, std::string formTarget);
	
		class	InternException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif