
#pragma once
#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include <string>

class	Dog : public Animal
{
	private:
		Brain	*brain;
	public:
	~Dog(void);
	Dog(void);
	Dog(const Dog &cpy);
	Dog &operator=(const Dog &cpy);

		void makeSound(void)const ;
};
