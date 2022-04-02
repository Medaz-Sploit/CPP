/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:52:41 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 01:53:28 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include <iostream>
# include <string>
# include <fstream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

#define SHRUBBERY_SIGN 145
#define SHRUBBERY_EXEC 137

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();

		std::string		getTarget(void) const;

		ShrubberyCreationForm &		operator=(ShrubberyCreationForm const & rhs);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string		_target;
};

std::ostream &			operator<<(std::ostream & o, ShrubberyCreationForm const & i);

#endif