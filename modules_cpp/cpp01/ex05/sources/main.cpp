#include "includes/main.hpp"

int main(int argc, char **argv)
{
	Harl ggg;
	std::string arg;

	if (argc != 2)
		return (1);
	arg = argv[1];
	for (size_t i = 0; i < arg.length(); i++)
		arg[i] = std::toupper(arg[i]);
	ggg.complain(arg);
}
