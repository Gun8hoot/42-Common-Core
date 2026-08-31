

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>
# include <string>

class Zombie
{
	private:
		std::string name;
	public:
		void announce(void);
		~Zombie(void);
		Zombie(void);
		void setName(std::string newName);
};

Zombie* zombieHorde( int N, std::string name );

#endif
