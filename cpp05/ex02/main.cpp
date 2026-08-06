
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <stdexcept>
#include <iostream>

int main(void)
{
	try
	{
		Bureaucrat user("user", 1);
		Bureaucrat user2("user2", 75);

		AForm		*form = new RobotomyRequestForm("form");

		user.signForm(form);
	}
	catch (std::exception &ex)
	{
		std::cerr << ex.what() << std::endl;
	}
}
