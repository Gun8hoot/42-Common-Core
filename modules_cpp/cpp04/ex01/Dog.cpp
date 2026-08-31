#include "Dog.hpp"

Dog::~Dog(void)
{
	std::cout << "Calling Dog destructor\n";
	if (this->brain)
		delete this->brain;
}

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "Calling Dog constructor\n";
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	this->type = cpy.type;
	this->brain = cpy.brain;
	std::cout << "Calling Dog constructor\n";
}

Dog	&Dog::operator=(const Dog &cpy)
{
	if (this != &cpy)
	{
		this->type = cpy.type;
		this->brain = cpy.brain;
	}
	std::cout << "Calling Dog constructor\n";
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << this->type << " said : Waouf\n";
}
