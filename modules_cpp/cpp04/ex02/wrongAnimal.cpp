
#include "wrongAnimal.hpp"

void	wrongAnimal::makeSound(void) const
{
	std::cout << this->type << " said : <wierd noise>\n";
}

wrongAnimal::wrongAnimal(void)
{
	std::cout << "Calling wrongAnimal constructor\n";
	this->type = "Unknown";
}

wrongAnimal::wrongAnimal(const wrongAnimal &cpy)
{
	std::cout << "Calling wrongAnimal constructor\n";
	this->type = cpy.type;
}

wrongAnimal &wrongAnimal::operator=(const wrongAnimal &cpy)
{
	std::cout << "Calling wrongAnimal constructor\n";
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	return (*this);
}

wrongAnimal::~wrongAnimal(void)
{
	std::cout << "Calling wrongAnimal destructor\n";
}
