#include "class/Zombie.hpp"

Zombie *newZombie(std::string l_name)
{
	Zombie  *zombie = new Zombie(l_name);
	if (!zombie)
	{
		std::cout << "Failed to allocated memory\n";
		return (NULL);
	}
	return (zombie);
}
