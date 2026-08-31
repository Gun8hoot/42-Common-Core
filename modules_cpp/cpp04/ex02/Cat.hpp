
#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class	Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		~Cat(void);
		Cat(void);
		Cat(const Cat &cpy);
		Cat &operator=(const Cat &cpy);

		void makeSound(void) const;
};
