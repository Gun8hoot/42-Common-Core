#include "class/Zombie.hpp"

int main(void)
{
	Zombie *horde;
	horde = zombieHorde(5, "Ed");
	if (!horde)
		return (1);
	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
