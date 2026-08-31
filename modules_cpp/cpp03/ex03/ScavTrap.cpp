#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_point = 50;
	this->_attack_damage = 20;
	this->_guardMode = false;
	std::cout << "ScavTrap \"" << this->getName() << "\" constructor called\n";
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	this->_name = cpy._name;
	this->_attack_damage = cpy._attack_damage;
	this->_energy_point = cpy._energy_point;
	this->_hit_point = cpy._hit_point;
	std::cout << "ScavTrap \"" << this->getName() << "\" constructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap& cpy)
{
	if (this != &cpy)
		*this = cpy;
	std::cout << "ScavTrap \"" << this->getName() << "\" constructor called\n";
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap \"" << this->getName() << "\" destructor called\n";
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hit_point <= 0)
		std::cout << "ScavTrap \"" << this->_name << "\" is dead!\n";
	else if (this->_energy_point > 0)
	{
		std::cout << "ScavTrap \"" << ScavTrap::_name << "\" attacks \"" << target << "\", causing " << this->_attack_damage << " points of damage!\n";
		this->_energy_point--;
	}
	else
		std::cout << "ScavTrap \"" << this->_name << "\" dont have enough energy points!\n";
}

void	ScavTrap::guardGate(void)
{
	if (this->_guardMode == false)
	{
		std::cout << "ScavTrap \"" << this->getName() << "\" is now in guard mode!\n";
		this->_guardMode = true;
	}
	else
	{
		std::cout << "ScavTrap \"" << this->getName() << "\" is no longer in guard mode!\n";
		this->_guardMode = false;
	}
}
