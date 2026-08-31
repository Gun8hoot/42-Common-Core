
#pragma once
#include <string>
#include <iostream>
#include "wrongAnimal.hpp"

class	wrongCat : public wrongAnimal
{
	public:
		~wrongCat(void);
		wrongCat(void);
		wrongCat(const wrongCat &cpy);
		wrongCat &operator=(const wrongCat &cpy);

		void makeSound(void) const;
};
