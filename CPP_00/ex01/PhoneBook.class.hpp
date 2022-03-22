/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 19:22:51 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/22 08:35:38 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

#include "Contact.class.hpp"

# define RESET			"\033[0m"
# define BLACK			"\033[30m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define YELLOW			"\033[33m"
# define BLUE			"\033[34m"
# define MAGENTA		"\033[35m"
# define CYAN			"\033[36m"
# define WHITE			"\033[37m"
# define BOLDBLACK		"\033[1m\033[30m"
# define BOLDRED		"\033[1m\033[31m"
# define BOLDGREEN		"\033[1m\033[32m"
# define BOLDYELLOW		"\033[1m\033[33m"
# define BOLDBLUE		"\033[1m\033[34m"
# define BOLDMAGENTA	"\033[1m\033[35m"
# define BOLDCYAN		"\033[1m\033[36m"
# define BOLDWHITE		"\033[1m\033[37m"

class PhoneBook
{
	private:
		static int	_contactNb;
		static int	_exit;
		Contact contact;

		std::string _queryInfo(std::string contactName);
		static int		_emptyPhoneBook(PhoneBook *account);
		int		_emptyinfos(PhoneBook account);
		void	_truncatePrint(std::string string);
		void		_printContacts(PhoneBook account);

	public:
		static int getContactNb(void);
		static int getExit(void);
		static void	addContact(PhoneBook &account);
		static void	searchContact(PhoneBook *account);

		PhoneBook();
		~PhoneBook();
};

#endif