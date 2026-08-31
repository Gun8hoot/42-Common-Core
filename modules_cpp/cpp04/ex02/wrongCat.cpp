
#include "wrongCat.hpp"

wrongCat::~wrongCat(void)
{
	std::cout << "Calling wrongCat destructor\n";
}

wrongCat::wrongCat(void) : wrongAnimal()
{
	this->type = "wrongCat";
	std::cout << "Calling wrongCat constructor\n";
}

wrongCat::wrongCat(const wrongCat &cpy) : wrongAnimal(cpy)
{
	this->type = cpy.type;
	std::cout << "Calling wrongCat constructor\n";
}

wrongCat	&wrongCat::operator=(const wrongCat &cpy)
{
	if (this != &cpy)
	{
		this->type = cpy.type;
	}
	std::cout << "Calling wrongCat constructor\n";
	return (*this);
}

void	wrongCat::makeSound(void) const
{
	std::cout << this->type << " said : Meaow\n";
}
