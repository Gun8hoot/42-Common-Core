
#include "ClapTrap.hpp"

int main(void)
{
	std::cout << "\x1b[38;5;2m[+] Constructor called\x1b[0m\n";
	ClapTrap alpha("alpha");
	ClapTrap beta("beta");
	ClapTrap gamma("gamma");
	ClapTrap delta("delta");
	ClapTrap epsilon("epsilon");

	std::cout << "\x1b[38;5;2m\n[+] Dead ClapTrap try to attack\x1b[0m\n";
	beta.takeDamage(10);
	beta.attack(alpha.getName());

	std::cout << "\x1b[38;5;2m\n[+] ClapTrap used his energy point\x1b[0m\n";
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(alpha.getName());
	alpha.takeDamage(0);
	gamma.attack(epsilon.getName());

	std::cout << "\x1b[38;5;2m\n[+] ClapTrap attack a dead claptrap\x1b[0m\n";
	alpha.attack(gamma.getName());
	alpha.takeDamage(1);

	std::cout << "\x1b[38;5;2m\n[+] Destructor called\x1b[0m\n";
}
