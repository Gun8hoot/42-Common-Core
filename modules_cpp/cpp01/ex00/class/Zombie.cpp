#include "class/Zombie.hpp"

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


Zombie::~Zombie(void)
{
	std::cout << this->name << " have been killed !" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}
