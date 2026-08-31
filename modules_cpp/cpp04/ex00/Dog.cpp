#include "Dog.hpp"

Dog::~Dog(void)
{
	std::cout << "Calling Dog destructor\n";
}

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	std::cout << "Calling Dog destructor\n";
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	this->type = cpy.type;
	std::cout << "Calling Dog destructor\n";
}

Dog	&Dog::operator=(const Dog &cpy)
{
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	std::cout << "Calling Dog destructor\n";
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->type << " said : Waouf\n";
}
