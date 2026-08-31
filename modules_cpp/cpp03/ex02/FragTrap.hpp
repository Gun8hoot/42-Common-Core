
#pragma once
# include <iostream>
# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap &cpy);
		FragTrap	&operator=(const FragTrap& cpy);
		~FragTrap(void);

		void	highFivesGuys(void);
		void	attack(const std::string &target);
};
