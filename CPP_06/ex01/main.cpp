/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:38:29 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 04:38:37 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "serialize.hpp"

void    test(Data *structToTest) {
    std::cout << "Addr base :\t\t\t" << structToTest << std::endl
        << "serialize ret :\t\t\t" << serialize(structToTest) << std::endl
        << "deserialize of serialize ret :\t" << deserialize(serialize(structToTest)) << std::endl;
    std::cout << "Are they the same :\t\t";
    if (deserialize(serialize(structToTest)) == structToTest)
        std::cout << "Whaoow ! [wink]" << std::endl;
    else
        std::cout << "Fail !" << std::endl;
}

int main() {
    Data    base = {1, 'c'};
    Data    *cpyPtr = &base;
    Data    lol = {23432, 34};
    Data    *nullPtr = NULL;

    test(&base);
    std::cout << std::endl;
    test(cpyPtr);
    std::cout << std::endl;
    test(nullPtr);
    std::cout << std::endl;
    test(&lol);
    return 0;
}