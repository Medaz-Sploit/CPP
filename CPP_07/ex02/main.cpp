/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 04:58:26 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 04:58:31 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <typeinfo>
#include "Array.hpp"

#define MAX_VAL 750
#define DEBUG 0

void    makeSubject() {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (DEBUG)
            std::cout << "numbers[" << i << "] : " << numbers[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete [] mirror;
            return ;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
}



int main(int, char**)
{
    std::cout << std::endl << "----------------Basic tests----------------" << std::endl << std::endl;
    Array<int>      lol;
    Array<float>    lel(10);

    for (unsigned int i = 0; i < lel.size(); i++)
    {
        lel[i] = 10.34 + i;
        std::cout << "lel[" << i << "] : " << lel[i] << std::endl;
    }
    try
    {
       lol[0] = 5;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << lel[111] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    std::cout << std::endl << "-------------------Subject tests------------------" << std::endl << std::endl;
    makeSubject();




    std::cout << std::endl << std::endl << "--------------Char tests-------------" << std::endl << std::endl;
    Array<char> abc(26);

    std::cout << "abc : " << std::endl;
    for (size_t i = 0; i < abc.size(); i++)
    {
        abc[i] = 97 + i;
    }
    for (size_t i = 0; i < abc.size(); i++)
    {
        std::cout << "\t" << abc[i] << std::endl;
    }


    std::cout << std::endl << std::endl << "--------------String tests--------------" << std::endl << std::endl;
    Array<std::string>  s(3);
    Array<std::string>  sCpy(s);

    sCpy[2] = "Wahow ! [wink]";
    s[1] = "Changement inopiné";
    std::cout << "s :" << std::endl;
    for (unsigned int i = 0; i < s.size(); i++)
    {
        std::cout << "\t" << s[i] << std::endl;
    }
    std::cout << "sCpy :" << std::endl;
    for (unsigned int i = 0; i < sCpy.size(); i++)
    {
        std::cout << "\t" << sCpy[i] << std::endl;
    }

    return 0;
}