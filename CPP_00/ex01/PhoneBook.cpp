/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 04:38:30 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/22 08:43:09 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

void Options(void)
{
	std::cout << YELLOW << "ADD: " << GREEN << "save a new contact" << std::endl << RESET;
	std::cout << YELLOW << "SEARCH: " << GREEN << "display a specific contact" << std::endl << RESET;
	std::cout << YELLOW << "EXIT: " << GREEN << "The program quits and the contacts are lost forever!" << std::endl << RESET;
}

int main(void)
{
	PhoneBook contact[8];
	std::string	command;

	Options();
	while (command != "EXIT")
	{
		if (PhoneBook::getExit() == 1)
			return (1);
		std::cout << BLUE << "ENTER A COMMAND : " << RESET;
		std::getline(std::cin, command);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		else if (command == "ADD")
			PhoneBook::addContact(contact[PhoneBook::getContactNb()]);
		else if (command == "SEARCH")
			PhoneBook::searchContact(contact);
		else if (command == "EXIT")
			std::cout << RED << "PhoneBook Exited Successfly ✅" << std::endl << RESET;
		else
			std::cout << RED << "🚨🚨🚨Please enter one of the following commands : ADD, SEARCH, EXIT" << std::endl << RESET;
	}
	return (0);
}