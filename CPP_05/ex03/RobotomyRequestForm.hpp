/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 01:49:01 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 01:49:56 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include "Form.hpp"
# include "Bureaucrat.hpp"

#define ROBOTOMY_SIGNE 72
#define ROBOTOMY_EXEC 45

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();

		std::string		getTarget(void) const;

		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);

		void	execute(Bureaucrat const & executor) const;

	private:
		std::string		_target;
};

std::ostream &			operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif