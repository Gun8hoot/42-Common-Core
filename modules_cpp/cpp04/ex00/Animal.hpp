
#pragma once
#include <string>
#include <iostream>

class	Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		virtual ~Animal(void);
		Animal(const Animal &cpy);
		Animal &operator=(const Animal &cpy);

		virtual void	makeSound(void) const;
};
