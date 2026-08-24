
#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <exception>
#include <stdexcept>
#include <iostream>
#include <sys/types.h>

int main(void)
{
	{
		std::cout << "\x1b[32m//// A VALID FORM WITH A VALID USER \\\\\\\\\n\x1b[0m";
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

  std::cout << std::endl;

	{
		std::cout << "\x1b[31m//// A USER CANNOT SIGN A FORM \\\\\\\\\n\x1b[0m";
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

	std::cout << std::endl;

	{
		std::cout << "\x1b[32m//// \"<<\" OPERATOR FOR FORM CLASS \\\\\\\\\n\x1b[0m";
		try
		{
			Form	aaa;
			std::cout << aaa << std::endl;
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
}
