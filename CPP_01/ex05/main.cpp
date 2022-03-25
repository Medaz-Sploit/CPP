/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 11:51:54 by mazoukni          #+#    #+#             */
/*   Updated: 2022/03/25 11:54:44 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl   lol;
    Harl   pouet;

    lol.complain("DEBUG");
    lol.complain("INFO");
    lol.complain("WARNING");
    lol.complain("ERROR");
    lol.complain("lol");

    std::cout << std::endl;

    void    (Harl::*f)( std::string );
    f = &Harl::complain;
    
    (lol.*f)("INFO");
    (pouet.*f)("pouet");

    return (0);
}