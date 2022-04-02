/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:02:08 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 05:02:10 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"
#include <map>
#include <vector>
#include <list>

int main() {
    std::cout << "--------------Try with vector---------" << std::endl;
    std::vector<int>                    vec(10, 100);
    std::vector<int>::const_iterator    vecIt;

    try
    {
        std::cout << *(easyfind(vec, 100)) << std::endl;
        vecIt = easyfind(vec, 8);
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    


    std::cout << "--------------Try with list---------" << std::endl;
    std::list<int>                      list;

    list.push_back(12);
    list.push_back(34);
    list.push_back(-23);
    list.push_back(456);
    list.push_back(6);
    try
    {
        std::cout << *(easyfind(list, 34)) << std::endl;
        std::cout << *(easyfind(list, 6)) << std::endl;
        std::cout << *(easyfind(list, -23)) << std::endl;
        easyfind(list, 100);
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }


    return 0;
}