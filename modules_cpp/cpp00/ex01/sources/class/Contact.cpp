
#include "includes/main.hpp"

static void  padding(std::string colums)
{
	std::size_t len = colums.length();

	std::cout << "|";
	for (std::size_t i = 0; i < 10; i++)
	{
		if (len > 10 && i == 9)
			std::cout << ".";
		else if (len < 10 && i >= len)
			std::cout << " ";
		else
			std::cout << colums[i];
	}
}

void	adding_prompt(std::string &line, std::string messages)
{
	while (line.empty() && !std::cin.eof())
	{
		std::cout << messages;
		std::getline(std::cin, line);
	}
}

void	Contact::display_contact(void)
{
	std::cout << "+----------+----------+----------+----------+" << std::endl;
	padding(this->first_name);
	padding(this->last_name);
	padding(this->nickname);
	padding(this->phone_number);
	std::cout << "|" << std::endl;
	std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void Contact::adding_contact(void)
{
	adding_prompt(this->first_name, "Enter the first name of the contact you want add : ");
	adding_prompt(this->last_name, "Enter the last name of the contact you want add : ");
	adding_prompt(this->nickname, "Enter the nickname of the contact you want add : ");
	adding_prompt(this->phone_number, "Enter the phone number of the contact you want add : ");
	adding_prompt(this->secret, "Enter the secret of the contact you want add : ");
	if (!std::cin.eof())
		std::cout << "The contact have been added !" << std::endl;
}
