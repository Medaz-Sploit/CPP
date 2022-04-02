/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazoukni <mazoukni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 05:03:50 by mazoukni          #+#    #+#             */
/*   Updated: 2022/04/02 05:04:03 by mazoukni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <ctime>
#include <cstdlib>

class Span
{
	private:
		unsigned int			_max;
		std::vector<int>		vec;

		class MaximumSizeException : public std::exception {
			public :
				virtual const char* what() const throw() {
				return "Maximum size reach";
			}
		};
		class NotEnougthSpaceException : public std::exception {
			public :
				virtual const char* what() const throw() {
				return "Not enougth space in Span";
			}
		};

	public:

		Span();
		Span( unsigned int N );
		Span( Span const & src );
		~Span();

		Span &			operator=( Span const & rhs );

		unsigned int	getMax() const;
		void			addNumber(int nb);
		void			addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
};

#endif