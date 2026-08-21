
# include "Bureaucrat.hpp"
# include "AForm.hpp"
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
	std::cout << __GREEN__ << __BOLD__ << "/// VALID TEST \\\\\\\\" << __RESET__ << std::endl;

	{
		std::cout << __RED__ << "//// ROBOTOMY REQUEST FORM \\\\\\\\" << __RESET__ << std::endl;
		try
		{
			Bureaucrat	user("user", 1);
			RobotomyRequestForm	form("Somebody");
			RobotomyRequestForm test(form);

			user.signForm(test);
			user.executeForm(test);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
	{
		std::cout << __RED__ << "//// SHRUBBERY CREATION FORM \\\\\\\\" << __RESET__ << std::endl;
		try
		{
			Bureaucrat	user("user", 1);
			ShrubberyCreationForm	form("sapin");
			ShrubberyCreationForm test(form);

			user.signForm(test);
			user.executeForm(test);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}

	{
		std::cout << __RED__ << "//// PRESIDENTIAL PARDON FORM \\\\\\\\" << __RESET__ << std::endl;
		try
		{
			Bureaucrat	user("user", 1);
			PresidentialPardonForm	form("president");
			PresidentialPardonForm test(form);

			user.signForm(test);
			user.executeForm(test);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
	{
		std::cout << __RED__ << "//// DISPLAY FORM DATA \\\\\\\\" << __RESET__ << std::endl;
		PresidentialPardonForm aaa("name");
		std::cout << aaa << std::endl;
	}
	std::cout << __GREEN__ << __BOLD__ << "/// INVALID TEST \\\\\\\\" << __RESET__ << std::endl;

	{
		std::cout << __RED__ << "//// TRY TO EXECUTE A NON-SIGNED FORM \\\\\\\\" << __RESET__ << std::endl;
		try
		{
			Bureaucrat	user("user", 150);
			ShrubberyCreationForm	form("sapin");
			ShrubberyCreationForm test = form;

			user.signForm(test);
			user.executeForm(test);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
	{
		std::cout << __RED__ << "//// GRADE IS TOO LOW TO EXEC \\\\\\\\" << __RESET__ << std::endl;
		try
		{
			Bureaucrat	user("user", 145);
			ShrubberyCreationForm	form("sapin");
			ShrubberyCreationForm test = form;

			user.signForm(test);
			user.executeForm(test);
		}
		catch (std::exception &ex)
		{
			std::cerr << ex.what() << std::endl;
		}
	}
}
