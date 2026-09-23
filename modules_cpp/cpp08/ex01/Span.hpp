#pragma once

#include <stdexcept>
#include <vector>
#include <cstddef>

class Span
{
private:
	unsigned int     _n;
	std::vector<int> _vec;

public:
	Span(void);
	Span(unsigned int n);
	Span(const Span &cpy);
	Span &operator=(const Span &cpy);
	~Span(void);

	void addNumber(int number);

	template <typename It>
	void addNumbers(It begin, It end)
	{
		std::size_t count = 0;
		for (It it = begin; it != end; ++it)
			++count;
		if (_vec.size() + count > _n)
			throw std::runtime_error("Too many numbers");
		_vec.insert(_vec.end(), begin, end);
	}

	int shortestSpan(void) const;
	int longestSpan(void) const;
};
