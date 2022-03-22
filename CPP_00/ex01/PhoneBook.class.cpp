/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:22:54 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/22 08:52:27 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

int PhoneBook::_contactNb = 0;
int PhoneBook::_exit = 0;

int PhoneBook::getExit(void)
{
	return PhoneBook::_exit;
}

int PhoneBook::getContactNb(void)
{
	return PhoneBook::_contactNb;
}

PhoneBook::PhoneBook()
{
	return;
}

PhoneBook::~PhoneBook()
{
	return;
}

std::string PhoneBook::_queryInfo(std::string contactName)
{
	std::string str;
	if (std::cin.eof())
	{
		std::cout << std::endl;
		PhoneBook::_exit = 1;
		return str;
	}
	std::cout << BOLDMAGENTA << "Enter the " << contactName << " : " << RESET;
	std::getline(std::cin, str);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		PhoneBook::_exit = 1;
		return str;
	}
	std::cout << "The " << contactName << " you entered is [" << YELLOW << str << RESET << "]" << std::endl;
	return (str);
}

void PhoneBook::addContact(PhoneBook &account)
{
	std::string userInput;

	if (PhoneBook::_contactNb >= 8)
	{
		std::cout << "The PhonBook is Full, No new contact can be added" << std::endl;
		return;
	}
	PhoneBook::_contactNb += 1;
	std::cout << BOLDGREEN << "You are addding a Contact of Index " << PhoneBook::_contactNb << std::endl;
	account.contact.setFirstName(account._queryInfo("First Name"));
	account.contact.setLastName(account._queryInfo("Last Name"));
	account.contact.setNickName(account._queryInfo("Nick Name"));
	account.contact.setPhoneNumber(account._queryInfo("Phone Number"));
	account.contact.setDarkestSecret(account._queryInfo("Darkest Secret"));
	return;
}

void PhoneBook::searchContact(PhoneBook *account)
{
	int id = 0;
	std::string index = "";

	if (PhoneBook::_emptyPhoneBook(account) == -1)
		return;
	std::cout << BOLDBLUE << "     index|First Name| Last Name| Nick Name|" << std::endl << RESET;
	while (id < PhoneBook::getContactNb())
	{
		if (account[id]._emptyinfos(account[id]))
		{
			std::cout << BOLDYELLOW << "         " << id + 1 << "|";
			account[id]._truncatePrint(account[id].contact.getFirstName());
			std::cout << "|";
			account[id]._truncatePrint(account[id].contact.getLastName());
			std::cout << "|";
			account[id]._truncatePrint(account[id].contact.getNickName());
			std::cout << "|";
			std::cout << RESET << std::endl;
		}
		id++;
	}
	std::cout << "Enter the desired Index to Show : ";
	std::getline(std::cin, index);
	if (std::cin.eof())
	{
		std::cout << std::endl;
		PhoneBook::_exit = 1;
		return;
	}
	if (index.empty())
		std::cout << RED << "🔔Please enter a valid Index.🔔" << RESET << std::endl;
	else
	{
		id = std::atoi(index.c_str());
		 if (id > 0 && id <= PhoneBook::getContactNb() && account[id - 1]._emptyinfos(account[id - 1]) != 0)
		 {
			 std::cout << BOLDGREEN << "============CONTACT INFOS============" << RESET << std::endl;
			 account[id - 1]._printContacts(account[id - 1]);
		 }
		 else
		 	std::cout << RED << "Please Try again with a valid Index." << RESET << std::endl;
	}
	return;
}

void		PhoneBook::_printContacts(PhoneBook account)
{
	std::cout << BOLDWHITE << "First Name         : " << BOLDYELLOW << account.contact.getFirstName() << RESET << std::endl;
	std::cout << BOLDWHITE << "Last Name          : " << BOLDYELLOW << account.contact.getLastName() << RESET << std::endl;
	std::cout << BOLDWHITE << "Nick Name          : " << BOLDYELLOW << account.contact.getNickName() << RESET << std::endl;
	std::cout << BOLDWHITE << "Phone Number       : " << BOLDYELLOW << account.contact.getPhoneNumber() << RESET << std::endl;
	std::cout << BOLDWHITE << "Darkest Secret     : " << BOLDYELLOW << account.contact.getDarkestSecret() << RESET << std::endl;
	return;
}

void	PhoneBook::_truncatePrint(std::string string)
{
	std::string name = string;
	int spaces = 10 - name.length();

	while (spaces > 0)
	{
		std::cout << " ";
		spaces--;
	}
	if (name.length() <= 10)
		std::cout << name;
	else
	{
		name.resize(9);
		std::cout << name << ".";
	}
	return;
}

int	PhoneBook::_emptyPhoneBook(PhoneBook *account)
{
	int i = 0;
	int emptyContact = 0;

	if (PhoneBook::getContactNb() == 0)
	{
		std::cout << RED << "🔔There is no contact, Please use ADD command to add new contacts.🔔" << std::endl << RESET;
		return (-1);
	}
	while (i < PhoneBook::getContactNb())
	{
		if (account[i]._emptyinfos(account[i]))
			emptyContact = 1;
		i++;
	}
	if (!emptyContact)
	{
		std::cout << RED << "🔔The contact is empty, Please use ADD command to add a valid Contact.🔔" << std::endl << RESET;
		return (-1);
	}
	return (0);
}

int	PhoneBook::_emptyinfos(PhoneBook account)
{
	if (account.contact.getFirstName().empty() && account.contact.getLastName().empty()
	 && account.contact.getNickName().empty() && account.contact.getPhoneNumber().empty()
	 && account.contact.getDarkestSecret().empty())
		return (0);
	return (1);
}