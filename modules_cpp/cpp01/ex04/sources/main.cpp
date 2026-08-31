#include "includes/main.hpp"

int main(int argc, char **argv)
{
	std::size_t		i;
	std::string		line;
	std::string		str1;
	std::string		str2;
	std::ifstream	file;
	std::ofstream	new_file;

	if (argc != 4)
	{
		if (argc == 1)
			std::cout << "Usage:\t" << argv[0] << " <input_file> <str_to_replace> <str_that_replace>\n\tThen an new file named \"new_file\" is created\n";
		else if (argc < 4)
			std::cout << "[!] Missing arguments !\n";
		else
			std::cout << "[!] Too many arguments !\n";
		return (1);
	}
	file.open(argv[1]);
	if (file.fail())
	{
		std::cout << "[!] Failed to open " << argv[1] << " !\n";
		return (1);
	}
	new_file.open("new_file", std::ios::trunc);
	if (new_file.fail())
	{
		std::cout << "[!] Failed to create/open " << argv[1] << " !\n";
		return (1);
	}
	str1 = argv[2];
	str2 = argv[3];
	if (str1.empty() || str2.empty())
		return (1);
	while (std::getline(file, line))
	{
		while ((i = line.find(str1)) != std::string::npos)
		{
			line.erase(i, str1.length()).insert(i, str2);
		}
		new_file << line << std::endl;
	}
	file.close();
	new_file.close();
	return (0);
}
