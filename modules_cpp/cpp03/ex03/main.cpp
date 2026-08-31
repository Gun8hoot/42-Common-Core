
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
	std::cout << "\x1b[38;5;2m[+] Constructor called\x1b[0m\n";
	DiamondTrap	dd("dd");

	std::cout << "\n\x1b[38;5;2m[+] Fragtrap do an high five\x1b[0m\n";
	dd.attack("Nothing");
	dd.WhoAmI();

	std::cout << "\x1b[38;5;2m\n[+] Destructor called\x1b[0m\n";
}
