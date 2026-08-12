
#pragma once

#include <vector>

class Span
{
	private:
		unsigned int		_n;
		std::vector<int>	_vec; // ???
	public:
		// -- CONSTRUCTOR --
		~Span(void);
		Span(unsigned int n);
		Span(const Span &cpy);
		Span	&operator=(const Span &cpy);

		// -- METHODES --
		void	addNumber(int number);
		int		shortestSpan(void);
		int		longestSpan(void);
};
