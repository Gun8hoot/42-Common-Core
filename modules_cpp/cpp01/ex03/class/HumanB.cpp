#include "class/HumanB.hpp"

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	;
}

void  HumanB::setWeapon(Weapon *weapon)
{
	if (weapon)
		this->weapon = weapon;
	else
		std::cout << "[!] Cannot attack with air\n";
}

void  HumanB::attack(void)
{
	if (this->weapon && this->weapon->getType() != "")
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " cant attack without a weapon" << std::endl;
}
