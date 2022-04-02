/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:45:19 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 01:46:27 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "Bureaucrat.hpp"

#define PRESIDENTIAL_SIGN 25
#define PRESIDENTIAL_EXEC 5

class PresidentialPardonForm : public Form
{

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();

		std::string		getTarget(void) const;

		PresidentialPardonForm &		operator=(PresidentialPardonForm const & rhs);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string		_target;
};

std::ostream &			operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif