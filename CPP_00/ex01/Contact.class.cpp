/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 20:49:12 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/22 08:30:36 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

std::string Contact::getFirstName()
{
	return this->_firstName;
}

std::string Contact::getLastName()
{
	return this->_lastName;
}

std::string Contact::getNickName()
{
	return this->_nickName;
}

std::string Contact::getPhoneNumber()
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret()
{
	return this->_darkestSecret;
}

void Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void Contact::setNickName(std::string nickName)
{
	this->_nickName = nickName;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

Contact::Contact()
{
	this->_firstName = "";
	this->_lastName = "";
	this->_nickName = "";
	this->_phoneNumber = "";
	this->_darkestSecret = "";
	return;
}

Contact::~Contact()
{
	return;
}