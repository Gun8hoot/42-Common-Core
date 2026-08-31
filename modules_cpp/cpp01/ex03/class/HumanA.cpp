#include "class/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	;
}

void HumanA::setWeapon(Weapon weapon) { this->weapon = weapon; }

void HumanA::attack(void) {
	if (this->weapon.getType() == "")
		std::cout << this->name << " cant attack without a weapon" << std::endl;
	else
		std::cout	<< this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
