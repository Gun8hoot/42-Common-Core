
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <stdexcept>

Base::~Base(void) { ; }

Base	*Base::generate(void)
{
	Base	*ptr = NULL;
	int		rd = time(NULL) % 3;

	try
	{
		switch (rd)
		{
			case 0:
				ptr = new A;
				std::cout << "Generated class A at " << ptr << std::endl;
				break;
			case 1:
				ptr = new B;
				std::cout << "Generated class B at " << ptr << std::endl;
				break;
			case 2:
				ptr = new C;
				std::cout << "Generated class C at " << ptr << std::endl;
				break;
			default:
				throw (std::runtime_error("Failed to generate valid random number"));
		}
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
	this->identify(&p);
}
