/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:08:43 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 05:08:45 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <list>
#include "MutantStack.hpp"

template< template <typename> class V>
void	makeTests(V<int> * leStack)
{
	leStack->push(5);
	leStack->push(17);

	std::cout << leStack->top() << std::endl;

	leStack->pop();

	std::cout << leStack->size() << std::endl;

	leStack->push(3);
	leStack->push(5);
	leStack->push(737);
	leStack->push(0);
    
	MutantStack<int>::iterator it = leStack->begin();
    MutantStack<int>::iterator ite = leStack->end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	printLol(int i) {
	std::cout << i << std::endl;
}

int main() {
	std::cout << "---------Mutant stack-------" << std::endl;
	MutantStack<int> mstack;
	makeTests<MutantStack>(&mstack);

	std::cout << "---------List-------" << std::endl;
	std::list<int>	liste;

	liste.push_front(5);	
	liste.push_front(17);

	std::cout << liste.front() << std::endl;

	liste.pop_front();

	std::cout << liste.size() << std::endl;

	liste.push_back(3);
	liste.push_back(5);
	liste.push_back(737);
	liste.push_back(0);

	for_each(liste.begin(), liste.end(), printLol);

	std::cout << "---------Real Stack-------" << std::endl;
	std::stack<int> s(mstack);
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	std::cout << "---------Mutant stack cpy-------" << std::endl;
	mstack.push(42);
	MutantStack<int> lol(mstack);
	lol.push(23487);
	makeTests<MutantStack>(&lol);
	std::cout << "deep cpy ? (print base mstack)" << std::endl;
	makeTests<MutantStack>(&mstack);

	return 0;
}
