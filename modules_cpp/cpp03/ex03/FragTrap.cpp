#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_point = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap \"" << this->getName() << "\" constructor called\n";
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "FragTrap \"" << this->getName() << "\" constructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap& cpy)
{
	if (this != &cpy)
		*this = cpy;
	std::cout << "FragTrap \"" << this->getName() << "\" constructor called\n";
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap \"" << this->getName() << "\" destructor called\n";
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_hit_point <= 0)
		std::cout << "FragTrap \"" << this->_name << "\" is dead!\n";
	else if (this->_energy_point > 0)
	{
		std::cout << "FragTrap \"" << FragTrap::_name << "\" attacks \"" << target << "\", causing " << this->_attack_damage  << " points of damage!\n";
		this->_energy_point--;
	}
	else
		std::cout << "FragTrap \"" << this->_name << "\" dont have enough energy points!\n";
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap \"" << this->getName() << "\" want to do an high-fives!\n";
}
