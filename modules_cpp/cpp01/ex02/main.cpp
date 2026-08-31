#include <iostream>

int main(void)
{
	std::string vars = "HI THIS IS BRAIN";
	std::string *stringPTR = &vars;
	std::string &stringREF = vars;

	std::cout << "[+] Current address of vars = " << &vars << std::endl;
	std::cout << "[+] Current address of stringPTR = " << &stringPTR << std::endl;
	std::cout << "[+] Current address of stringREF = " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "[+] Current value of vars = " << vars << std::endl;
	std::cout << "[+] Current value of stringPTR = " << *stringPTR << std::endl;
	std::cout << "[+] Current value of stringREF = " << stringREF << std::endl;
	return (0);
}
