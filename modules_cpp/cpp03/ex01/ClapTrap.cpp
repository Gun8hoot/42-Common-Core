#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_attack_damage = 0;
	this->_energy_point = 10;
	this->_hit_point = 10;
	std::cout << "ClapTrap \"" << this->getName() << "\" constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap &cpy)
{
	this->_name = cpy._name;
	this->_attack_damage = cpy._attack_damage;
	this->_energy_point = cpy._energy_point;
	this->_hit_point = cpy._hit_point;
	std::cout << "ClapTrap \"" << this->getName() << "\" constructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap& cpy)
{
	if (this != &cpy)
		*this = cpy;
	std::cout << "ClapTrap \"" << this->getName() << "\" constructor called\n";
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap \"" << this->getName() << "\" destructor called\n";
	this->_name = "";
	this->_hit_point = 0;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit_point <= 0)
		std::cout << "ClapTrap \"" << this->_name << "\" is dead!\n";
	else if (this->_energy_point > 0)
	{
		std::cout << "ClapTrap \"" << ClapTrap::_name << "\" attacks \"" << target << "\", causing " << this->_attack_damage << " points of damage!\n";
		this->_energy_point--;
	}
	else
		std::cout << "ClapTrap \"" << this->_name << "\" dont have enough energy points!\n";
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_point <= 0)
		std::cout << "ClapTrap \"" << this->_name << "\" is already dead!\n";
	else
	{
		this->_hit_point -= amount;
		std::cout << "ClapTrap \"" << ClapTrap::_name << "\" has taken " << amount << " points of damage!\n";
	}
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_point > 0 && this->_hit_point > 0 && this->_hit_point < 10)
	{
		std::cout << "ClapTrap \"" << this->_name << "\" has been repaired by " << amount << " hp!\n";
		this->_hit_point += amount;
		this->_energy_point--;
	}
	else
		std::cout << "ClapTrap \"" << this->_name << "\" cannot be repaired!\n";
}

std::string ClapTrap::getName(void)
{
	return (this->_name);
}
