
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\x1b[38;5;2m[+] Constructor called\x1b[0m\n";
	ClapTrap	alice("alice");
	ScavTrap	jjj("jayjay");

	std::cout << "\n\x1b[38;5;2m[+] Guard mode and kill a ClapTrap\x1b[0m\n";
	jjj.guardGate();
	jjj.attack(alice.getName());
	alice.takeDamage(0);
	jjj.guardGate();
	alice.attack(jjj.getName());
	jjj.takeDamage(30);

	std::cout << "\x1b[38;5;2m\n[+] Destructor called\x1b[0m\n";
}
