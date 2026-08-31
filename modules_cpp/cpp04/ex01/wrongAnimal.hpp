
#pragma once
#include <string>
#include <iostream>

class	wrongAnimal
{
	protected:
		std::string	type;
	public:
		wrongAnimal(void);
		virtual ~wrongAnimal(void);
		wrongAnimal(const wrongAnimal &cpy);
		wrongAnimal &operator=(const wrongAnimal &cpy);

		void	makeSound(void) const;
};
