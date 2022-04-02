/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:04:14 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 05:04:47 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _max(0)
{
	return ;
}

Span::Span( unsigned int N ) : _max(N)
{
	return ;
}

Span::Span( const Span & src )
{
	*this = src;
	return ;
}

Span::~Span()
{
}

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		this->_max = rhs._max;
	}
	return *this;
}

void				Span::addNumber(int nb)
{
	if (this->vec.size() >= this->_max)
		throw Span::MaximumSizeException();
	this->vec.push_back(nb);
}

void				Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	(void)start; (void)end;
	if (std::distance(start, end) > this->_max)
		throw Span::NotEnougthSpaceException();
	this->vec.insert(this->vec.begin(), start, end);
}


unsigned int		Span::shortestSpan() const
{
	if (this->vec.size() == 0 || this->vec.size() == 1)
		throw "Can't process shortestSpan()";

	int					shortest;
	int					tmp;
	std::vector<int>	cpy(this->vec.begin(), this->vec.end());
	std::vector<int>::iterator	it = cpy.begin();	

	std::sort(cpy.begin(), cpy.end());
	shortest = std::max(*it, *(it + 1)) - std::min(*it, *(it + 1));
	it++;
	while(it < cpy.end())
	{
		tmp = std::max(*it, *(it + 1)) - std::min(*it, *(it + 1));
		if (tmp < shortest)
			shortest = tmp;
		++it;
	}
	return shortest;
}

unsigned int		Span::longestSpan() const
{
	if (this->vec.size() == 0 || this->vec.size() == 1)
		throw "Can't process longestSpan()";

	return (*std::max_element(this->vec.begin(), this->vec.end()) -
			*std::min_element(this->vec.begin(), this->vec.end()));
}

unsigned int		Span::getMax() const {
	return this->_max;
}
