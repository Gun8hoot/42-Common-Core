
#pragma once
#include <string>
#include <iostream>

class	Animal
{
	protected:
		std::string	type;
		Animal(void);
		Animal(const Animal &cpy);
		Animal &operator=(const Animal &cpy);
	public:
		virtual ~Animal(void) = 0;

		virtual void	makeSound(void) const = 0;
};
