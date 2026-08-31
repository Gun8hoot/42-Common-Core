
# include "Bureaucrat.hpp"
# include "AForm.hpp"
#include "Intern.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

# include <stdexcept>
# include <iostream>

# define __RED__ "\x1b[31m"
# define __GREEN__ "\x1b[32m"
# define __RESET__ "\x1b[0m"
# define __BOLD__ "\x1b[1m"

int main(void)
{
	std::cout << __GREEN__ << __BOLD__ << "/// VALID TEST \\\\\\\\" << std::endl;
	{
		std::cout << __RED__ << "//// INTERN CREATE ROBOTOMY REQUEST FORM \\\\\\\\" << __RESET__ << std::endl;
		try
		{
			Bureaucrat	user("user", 1);
			Intern	intern;
			AForm		*form;

			form = intern.makeForm("robotomy request", "someone");

			user.signForm(*form);
			user.executeForm(*form);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	{
		std::cout << __RED__ << "//// INTERN CREATE PRESIDENTIAL PARDON FORM \\\\\\\\" << __RESET__ << std::endl;
		try
		{
			Bureaucrat	user("user", 1);
			Intern	intern;
			AForm		*form;

			form = intern.makeForm("presidential pardon", "someone");

			user.signForm(*form);
			user.executeForm(*form);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	{
		std::cout << __RED__ << "//// INTERN CREATE SHRUBBERY CREATION FORM \\\\\\\\" << __RESET__ << std::endl;
		try
		{
			Bureaucrat	user("user", 1);
			Intern	intern;
			AForm		*form;

			form = intern.makeForm("shrubbery creation", "something");

			user.signForm(*form);
			user.executeForm(*form);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	std::cout << __GREEN__ << __BOLD__ << "/// INVALID TEST \\\\\\\\" << __RESET__ << std::endl;
	{
		std::cout << __RED__ << "//// INTERN CREATE DONOTEXIST FORM \\\\\\\\" << __RESET__ << std::endl;
		try
		{
			Bureaucrat	user("user", 1);
			Intern	intern;
			AForm		*form;

			form = intern.makeForm("DONOTEXIST", "form");

			user.signForm(*form);
			user.executeForm(*form);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
}
