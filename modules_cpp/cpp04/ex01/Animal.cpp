
#include "Animal.hpp"

void	Animal::makeSound(void) const
{
	std::cout << this->type << " said : <wierd noise>\n";
}

Animal::Animal(void)
{
	std::cout << "Calling Animal constructor\n";
	this->type = "Unknown";
}

Animal::Animal(const Animal &cpy)
{
	std::cout << "Calling Animal constructor\n";
	this->type = cpy.type;
}

Animal &Animal::operator=(const Animal &cpy)
{
	std::cout << "Calling Animal constructor\n";
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Calling Animal destructor\n";
}
