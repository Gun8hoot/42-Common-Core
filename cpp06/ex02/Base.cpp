
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base::~Base(void) { ; }

Base	*Base::generate(void)
{
	Base	*ptr = NULL;
	int		rd = time(NULL) % 3;

	try
	{
		if (rd == 0)
			ptr = new A;
		else if (rd == 1)
			ptr = new B;
		else
			ptr = new C;
	}
	catch (std::bad_alloc &ex)
	{
		std::cerr << "Failed to allocated memory!" << std::endl;
		ptr = NULL;
	}
	return (ptr);
}

void	Base::identify(Base *p)
{
	if (p == NULL)
		std::cout << p << " is not instantiate" << std::endl;
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << p << " is a A struct" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << p << " is a B struct" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << p << " is a C struct" << std::endl;
	else
		std::cout << p << " is not a A,B or C struct" << std::endl;
}

void	Base::identify(Base &p)
{
	if (dynamic_cast<A *>(&p) != NULL)
		std::cout << &p << " is a A struct" << std::endl;
	else if (dynamic_cast<B *>(&p) != NULL)
		std::cout << &p << " is a B struct" << std::endl;
	else if (dynamic_cast<C *>(&p) != NULL)
		std::cout << &p << " is a C struct" << std::endl;
	else
		std::cout << &p << " is not a A,B or C struct" << std::endl;
}
