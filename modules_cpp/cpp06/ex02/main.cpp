
#include "Base.hpp"

#include <unistd.h>
#include <iostream>

int main(void)
{
	// Base	b2 = NULL;

	std::cout << "Using reference to identify" << std::endl;
	{
		Base	*base = NULL;

		base = base->generate();
		base->identify(base);
		if (base != NULL)
			delete base;
	}
	std::cout << std::endl;
	std::cout << "Using ptr to identify" << std::endl;

}
