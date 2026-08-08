
#include <cstring>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "[!] Usage : " << basename(argv[0]) << " {number}" << std::endl;
		return (1);
	}
}
