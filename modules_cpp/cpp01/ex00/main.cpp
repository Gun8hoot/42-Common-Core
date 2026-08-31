#include "class/Zombie.hpp"

int main(void)
{
	Zombie *first = newZombie("goffy");
	Zombie *second = newZombie("sora");
	first->announce();
	second->announce();
	randomChump("tmp1");
	randomChump("tmp2");

	delete first;
	delete second;
	return (0);
}
