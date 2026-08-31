
#include "includes/main.hpp"

void  search(PhoneBook phonebook)
{
	std::string	tmp;
	int index = 0;

	if (phonebook.recorded == 0)
	{
		std::cout << "The contact list is empty." << std::endl;
		return ;
	}
	while ((index < 1 || index > 8) && index < phonebook.recorded && std::cin.eof() == 0)
	{
		std::cout <<  phonebook.recorded << " index saved."<< std::endl;
		while (index == 0)
		{
			tmp = "";
			std::cout << "Enter the index of the contact you want see : ";
			std::getline(std::cin, tmp);
			if (std::cin.eof() == 1)
				return ;
			if (tmp.length() == 1 && stoi(tmp, index) != -1)
				break ;
		}
	}
	if (index >= 1 && index <= 8)
	{
		phonebook.contact[index - 1].display_contact();
	}
}
