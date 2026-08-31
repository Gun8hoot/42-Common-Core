
#include "Cat.hpp"

Cat::~Cat(void)
{
	std::cout << "Calling Cat destructor\n";
}

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	std::cout << "Calling Cat constructor\n";
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	this->type = cpy.type;
	std::cout << "Calling Cat constructor\n";
}

Cat	&Cat::operator=(const Cat &cpy)
{
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	std::cout << "Calling Cat constructor\n";
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->type << " said : Meaow\n";
}
