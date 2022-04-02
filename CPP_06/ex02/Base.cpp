/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:40:37 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 06:46:31 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {
    if (DEBUG)
        std::cout << "Base destructor called" << std::endl;
    return ;
}

Base*   generate(void) {
    int ranNb = std::rand();

    if (!(ranNb % 5))
    {
        if (DEBUG)
            std::cout << "generate an A" << std::endl;
        return new A;
    }
    else if (!(ranNb % 3))
    {
        if (DEBUG)
            std::cout << "generate a B" << std::endl;
        return new B;
    }
    else
    {
        if (DEBUG)
            std::cout << "generate a C" << std::endl;
        return new C;
    }
}

void    identify(Base* p) {
    A*  ptrA = dynamic_cast<A *>(p);
    if (ptrA)
    {
        std::cout << "A" << std::endl;
        return ;
    }
    B*  ptrB = dynamic_cast<B *>(p);
    if (ptrB)
    {
        std::cout << "B" << std::endl;
        return ;
    }
    C*  ptrC = dynamic_cast<C *>(p);
    if (ptrC)
    {
        std::cout << "C" << std::endl;
        return ;
    }
}

void    identify(Base& p) {
    try {
        A & refA = dynamic_cast<A &>(p);
        (void) refA;
        std::cout << "A" << std::endl;
        return ;
    }
    catch (std::exception& e) { if (DEBUG) std::cerr << e.what() << std::endl;}
    try {
        B & refB = dynamic_cast<B &>(p);
        (void) refB;
        std::cout << "B" << std::endl;
        return ;
    }
    catch (std::exception& e) { if (DEBUG) std::cerr << e.what() << std::endl;}
    try {
        C & refC = dynamic_cast<C &>(p);
        (void) refC;
        std::cout << "C" << std::endl;
        return ;
    }
    catch (std::exception& e) { if (DEBUG) std::cerr << e.what() << std::endl;}
}