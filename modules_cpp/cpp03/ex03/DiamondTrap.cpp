#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	this->_hit_point = FragTrap::_hit_point;
	this->_energy_point = ScavTrap::_energy_point;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << "DiamondTrap \"" << this->getName() << "\" constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy) : ClapTrap(cpy), ScavTrap(cpy), FragTrap(cpy)
{
	std::cout << "DiamondTrap \"" << this->getName() << "\" constructor called\n";
}

DiamondTrap::~DiamondTrap(void)
{
	this->_hit_point = 0;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy)
{
	if (this != &cpy)
	{
		ClapTrap::operator=(cpy);
		FragTrap::operator=(cpy);
		ScavTrap::operator=(cpy);
		this->_name = cpy._name;
	}
	return (*this);
}

void DiamondTrap::WhoAmI(void)
{
	std::cout << "The name of DiamondTrap is \"" << this->_name << "\" but also known as \"" << ClapTrap::_name << "\" under his ClapTrap name\n";
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
