
#pragma once
# include <iostream>
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include "ClapTrap.hpp"

class	DiamondTrap : public ScavTrap, public FragTrap
{
	private:
		std::string _name;
	public:
		DiamondTrap &operator=(const DiamondTrap &cpy);
		DiamondTrap(const DiamondTrap &cpy);
		DiamondTrap(std::string name);
		~DiamondTrap(void);

		void	attack(const std::string &target);
		void	WhoAmI(void);
};
