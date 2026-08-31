#include "includes/main.hpp"

void	help(void)
{
	std::cout << std::endl;
	std::cout << "   ╔═══════════ PHONEBOOK ═══════════╗\n";
	std::cout << "   ║                                 ║\n";
	std::cout << "   ╠═══ ADD: Adding a contact        ║\n";
	std::cout << "   ║                                 ║\n";
	std::cout << "   ╠═══ SEARCH: See saved contact    ║\n";
	std::cout << "   ║                                 ║\n";
	std::cout << "   ╚═══ EXIT: Leave PHONEBOOK ═══════╝\n";
	std::cout << std::endl;
}

int main(void)
{
	std::string line;
	PhoneBook phonebook;

	help();
	while (1)
	{
		line = "";
		std::cout << "Phonebook >> ";
		std::getline(std::cin, line);
		if (line.compare("ADD") == 0)
			add(phonebook);
		else if (line.compare("SEARCH") == 0)
			search(phonebook);
		if (line.compare("EXIT") == 0 || std::cin.eof() == 1)
			break;
	}
	if (line.empty())
		std::cout << std::endl;
	return (0);
}
