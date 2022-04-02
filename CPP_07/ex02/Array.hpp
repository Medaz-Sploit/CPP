/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:58:02 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 04:58:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template< typename T>
class Array
{
	private:
		unsigned int	_baseSize;

	public:
		T*				array;


		Array() :  _baseSize(0), array(new T[0]){ };
		Array( unsigned int n) : _baseSize(n), array(new T[n]) {
			for (unsigned int i = 0; i < n; i++)
			{
				array[i] = 0;
			}
		};
		Array( Array const & src ) {
			*this = src;
		};
		~Array() { if(this->array != NULL) delete [] this->array; };


		Array &		operator=( Array const & rhs ) {
			if ( this != &rhs )
			{
				this->_baseSize = rhs._baseSize;
				this->array = new T[rhs._baseSize];
				for (unsigned int i = 0; i < this->_baseSize; i++)
				{
					this->array[i] = rhs.array[i];
				}
			}
			return *this;
		};
		T &		operator[]( unsigned int const index) {
			if (index >= this->_baseSize || this->_baseSize == 0)
				throw Array::BadIndexException();
			return this->array[index];
		};


		unsigned int	size() const;


		class	BadIndexException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return ("Invalid index");
					}
		};	
};

template< typename T>
unsigned int			Array<T>::size() const
{
	return this->_baseSize;
}

template <>
class Array<std::string>
{
	private:
		unsigned int	_baseSize;

	public:
		std::string*	array;


		Array() :  _baseSize(0), array(new std::string[0]){ };
		Array( unsigned int n) : _baseSize(n), array(new std::string[n]) {
			for (unsigned int i = 0; i < n; i++)
			{
				array[i] = "Default";
			}
		};
		Array( Array const & src ) {
			*this = src;
		};
		~Array() { if(this->array != NULL) delete [] this->array; };


		Array &		operator=( Array const & rhs ) {
			if ( this != &rhs )
			{
				this->_baseSize = rhs._baseSize;
				this->array = new std::string[rhs._baseSize];
				for (unsigned int i = 0; i < this->_baseSize; i++)
				{
					this->array[i] = rhs.array[i];
				}
			}
			return *this;
		};
		std::string &		operator[]( unsigned int const index) {
			if (index >= this->_baseSize || this->_baseSize == 0)
				throw Array::BadIndexException();
			return this->array[index];
		};

		unsigned int	size() const {
			return this->_baseSize;
		};


		class	BadIndexException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return ("Invalid index");
					}
		};
};


template< typename T>
std::ostream &			operator<<( std::ostream & o, Array<T> const & i ) {
	o << i.array;
	return o;
};

#endif