
#include "Base.hpp"

#include <unistd.h>
#include <iostream>

int main(void)
{
	Base	*base = NULL;
	// Base	b2 = NULL;

	{
		std::cout << "Basic case" << std::endl;
		base = base->generate();
		base->identify(base);
		if (base != NULL)
			delete base;
	}
}
