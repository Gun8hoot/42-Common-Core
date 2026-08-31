
#include "Cat.hpp"

Cat::~Cat(void)
{
	std::cout << "Calling Cat destructor\n";
	if (this->brain)
		delete this->brain;
}

Cat::Cat(void) : Animal()
{
	this->type = "Cat";
	this->brain = new Brain;
	std::cout << "Calling Cat constructor\n";
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	this->type = cpy.type;
	this->brain = new Brain;
	std::cout << "Calling Cat constructor\n";
}

Cat	&Cat::operator=(const Cat &cpy)
{
	if (this != &cpy)
	{
		this->type = cpy.type;
		this->brain = new Brain;
	}
	std::cout << "Calling Cat constructor\n";
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->type << " said : Meaow\n";
}
