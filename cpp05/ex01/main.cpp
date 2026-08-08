
#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <stdexcept>
#include <iostream>

int main(void)
{
	{
		std::cout << "\x1b[1mA valid user sign a valid form : \n\x1b[0m\x1b[0m";
		try
		{
			Bureaucrat user("user", 1);

			Form			form1("Super amazing form");

			user.signForm(form1);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	{
		std::cout << "\x1b[1mUser grade is too low to sign a form : \n\x1b[0m\x1b[0m";
		try
		{
			Bureaucrat user("user", 150);

			Form			form1("Super amazing form", 50, 50);

			user.signForm(form1);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
}
