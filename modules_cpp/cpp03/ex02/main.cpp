
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	std::cout << "\x1b[38;5;2m[+] Constructor called\x1b[0m\n";
	ClapTrap	alice("alice");
	ScavTrap	jjj("jayjay");
	FragTrap	frag("frag");

	std::cout << "\n\x1b[38;5;2m[+] Fragtrap do an high five\x1b[0m\n";
	frag.highFivesGuys();

	std::cout << "\x1b[38;5;2m\n[+] Destructor called\x1b[0m\n";
}
