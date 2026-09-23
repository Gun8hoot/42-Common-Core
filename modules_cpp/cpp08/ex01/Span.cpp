#include "Span.hpp"

#include <algorithm>
#include <cstddef>
#include <limits>
#include <stdexcept>
#include <vector>

Span::Span(void) : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &cpy) : _n(cpy._n), _vec(cpy._vec) {}

Span &Span::operator=(const Span &cpy)
{
	if (this != &cpy)
	{
		_n = cpy._n;
		_vec = cpy._vec;
	}
	return *this;
}

Span::~Span(void) {}

void Span::addNumber(int number)
{
	if (_vec.size() >= _n)
		throw std::runtime_error("Too many numbers");
	_vec.push_back(number);
}

int Span::shortestSpan(void) const
{
	if (_vec.size() < 2)
		throw std::runtime_error("Not enough numbers stored");

	std::vector<int> cpy(_vec);
	std::sort(cpy.begin(), cpy.end());

	int min = std::numeric_limits<int>::max();
	for (std::size_t i = 0; i + 1 < cpy.size(); ++i)
	{
		int span = cpy[i + 1] - cpy[i];
		if (span < min)
			min = span;
	}
	return min;
}

int Span::longestSpan(void) const
{
	if (_vec.size() < 2)
		throw std::runtime_error("Not enough numbers stored");

	int max = *std::max_element(_vec.begin(), _vec.end());
	int min = *std::min_element(_vec.begin(), _vec.end());
	return max - min;
}
