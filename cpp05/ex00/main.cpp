
#include "Bureaucrat.hpp"

#include <stdexcept>
#include <iostream>

int main(void)
{
	Bureaucrat user("user");

	try
	{
		user.setGrade(1);
	}
	catch (std::exception &exc)
	{
		std::cout << exc.what();
	}
}
