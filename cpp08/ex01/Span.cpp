
#include "Span.hpp"

#include <algorithm>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <vector>

// -- CONSTRUCTOR --
Span::~Span(void) { ; }
Span::Span(unsigned int n) : _n(n) {;}
Span::Span(const Span &cpy)
{
	if (this != &cpy)
	{
		this->_vec = cpy._vec;
		this->_n = cpy._n;
	}
}
Span	&Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		this->_vec = cpy._vec;
		this->_n = cpy._n;
	}
	return (*this);
}

// -- METHODE --
void	Span::addNumber(int number)
{
	if (_vec.size() >= this->_n)
		throw (std::runtime_error("Too many number!"));
	_vec.push_back(number);
}
int		Span::shortestSpan(void)
{
	int min = std::numeric_limits<int>::max();
	std::vector<int> cpy;
	int span;

	if (this->_vec.size() == 0 || this->_vec.size() == 1)
		throw (std::runtime_error("Not enough number are store!"));

	cpy = this->_vec;
	std::sort(cpy.begin(), cpy.end());

	for (std::size_t i = 0; i < cpy.size() - 1 ; i++)
	{
		span = cpy[i + 1] - cpy[i];
		if (span < min)
			min = span;
	}
	return (span);
}
int		Span::longestSpan(void)
{
	if (this->_vec.size() == 0 || this->_vec.size() == 1)
		throw (std::runtime_error("Not enough number are store!"));
	return (*std::max_element(this->_vec.begin(), this->_vec.end()) - *std::min_element(this->_vec.begin(), this->_vec.end()));
}
