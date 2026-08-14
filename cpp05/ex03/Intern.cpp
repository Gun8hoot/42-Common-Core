
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cctype>
#include <exception>
#include <string>
#include <iostream>

const char	*Intern::InvalidFormType::what() const throw()
{
	return ("The form type you have enter is not valid");
}

Intern::Intern(void) { ; };

Intern::Intern(const Intern &cpy) { (void)cpy; };

Intern	&Intern::operator=(const Intern &cpy) { (void)cpy; return (*this);};

Intern::~Intern(void) {;};

static	AForm	*createPresidential(const std::string name)
{
	AForm	*frm = NULL;

	frm = new PresidentialPardonForm(name);
	if (!frm)
		throw (std::bad_alloc());
	return (frm);
}

static	AForm	*createRobotomy(const std::string name)
{
	AForm	*frm = NULL;

	frm = new RobotomyRequestForm(name);
	if (!frm)
		throw (std::bad_alloc());
	return (frm);
}

static	AForm	*createShrubbery(const std::string name)
{
	AForm	*frm = NULL;

	frm = new ShrubberyCreationForm(name);
	if (!frm)
		throw (std::bad_alloc());
	return (frm);
}

AForm	*Intern::makeForm(std::string form_target, const std::string target_of_form) const
{
	AForm		*ptr = NULL;
	std::string	formType[3] = {"robotomy request", "presidential pardon" , "shrubbery creation"};
	AForm		*(*func[3])(std::string) = {&createRobotomy, &createPresidential, &createShrubbery};

	for (int i = 0; i < 3; i++)
	{
		if (form_target.compare(formType[i]) == 0)
		{
			ptr = (func[i])(target_of_form);
			return (ptr);
		}
	}
	throw (Intern::InvalidFormType());
}
