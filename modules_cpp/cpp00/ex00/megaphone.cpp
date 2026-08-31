#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; i < argc; i++)
	{
		std::string converted(argv[i]);
		std::size_t len = converted.length();
		for (std::size_t j = 0; j < len; j++)
		{
			std::cout << (char)std::toupper(converted[j]);
			if (j == len - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
