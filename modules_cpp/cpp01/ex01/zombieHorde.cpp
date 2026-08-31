#include "class/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];
	if (!horde)
	{
		std::cout << "[!] Failed to allocate memory to create the horde\n";
		return (NULL);
	}
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return (horde);
}
