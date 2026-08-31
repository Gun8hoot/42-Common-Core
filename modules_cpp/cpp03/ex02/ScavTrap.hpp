
#pragma once
# include <iostream>
# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		bool _guardMode;
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &cpy);
		ScavTrap	&operator=(const ScavTrap& cpy);
		~ScavTrap(void);

		void	guardGate(void);
		void	attack(const std::string &target);
};
