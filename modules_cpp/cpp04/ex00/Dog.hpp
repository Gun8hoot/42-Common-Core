
#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"

class	Dog : public Animal
{
	public:
	~Dog(void);
	Dog(void);
	Dog(const Dog &cpy);
	Dog &operator=(const Dog &cpy);

		void makeSound(void)const ;
};
