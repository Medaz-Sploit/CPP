/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:08:28 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 05:08:29 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <deque>
#include <algorithm>

template< typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack(){};
        MutantStack(MutantStack<T> const & src) {
            *this = src;
        }
        ~MutantStack(){};
        
	MutantStack<T> & operator=(MutantStack<T> const & rhs) {
            if (this != &rhs)
                this->c = rhs.c;
            return *this;
        }

        typedef typename std::deque<T>::iterator iterator;

        iterator    begin() { return this->c.begin();}
        iterator    end() { return this->c.end();}
};

#endif
