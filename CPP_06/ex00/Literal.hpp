/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Literal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:27:15 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 04:33:16 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LITERAL_HPP
# define LITERAL_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <limits.h>

#define TYPE_CHAR "Char"
#define TYPE_INT "Int"
#define TYPE_FLOAT "Float"
#define TYPE_DOUBLE "Double"
#define TYPE_NONE "None"

class Literal
{
	public:
		Literal( Literal const & src );
		Literal(std::string src);
		~Literal();

		std::string		getStringLiteral() const;
		std::string		getType() const;
		double			getDoubleLiteral() const;
		void			setType();
		char			getCastChar() const;
		int				getCastInt() const;
		float			getCastFloat() const;
		double			getCastDouble() const;
		void			printAll() const;
		void			printDebug() const;

		Literal &		operator=( Literal const & rhs );

		class	CastErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	NonPrintErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class	ImpossiblePrintErrorException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	private:
		Literal();
		std::string	const	_stringLiteral;
		double				_doubleLiteral;
		std::string			_type;
		
		bool			isChar() const;
		bool			isInt() const;
		bool			isFloat() const;
		bool			isDouble() const;
		void			printChar() const;
		void			printInt() const;
		void			printFloat() const;
		void			printDouble() const;
};


#endif