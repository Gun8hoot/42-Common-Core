#include "class/Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie::~Zombie(void)
{
	std::cout << this->name << " have been killed !" << std::endl;
	this->name = "";
}

Zombie::Zombie(void)
{
	;
}

void	Zombie::setName(std::string newName)
{
	this->name = newName;
}
