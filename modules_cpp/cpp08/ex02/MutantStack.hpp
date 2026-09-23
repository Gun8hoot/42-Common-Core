#pragma once

#include <cstddef>
#include <iterator>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;

	MutantStack(void) {}
	MutantStack(const MutantStack &cpy) : std::stack<T>(cpy) {}
	MutantStack &operator=(const MutantStack &cpy)
	{
		if (this != &cpy)
			std::stack<T>::operator=(cpy);
		return *this;
	}
	~MutantStack(void) {}

	iterator       begin(void)       { return this->c.begin(); }
	iterator       end(void)         { return this->c.end(); }
	const_iterator begin(void) const { return this->c.begin(); }
	const_iterator end(void)   const { return this->c.end(); }
};
