
#pragma once
# include <iostream>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hit_point;		// Health of claptrap
		int			_energy_point;	// ??
		int			_attack_damage;	// The number of damages done to other claptrap

	public:
		~ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &cpy);
		ClapTrap	&operator=(const ClapTrap& cpy);

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

		std::string	getName(void);
};
