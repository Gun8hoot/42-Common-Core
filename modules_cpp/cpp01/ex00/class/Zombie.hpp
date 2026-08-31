#ifndef ZOMBIE_H
# define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		void announce(void);
		~Zombie();
		Zombie(std::string name);
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);

#endif // !ZOMBIE_H
