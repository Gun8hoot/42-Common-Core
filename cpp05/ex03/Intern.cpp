
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <exception>

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

	frm = new PresidentialPardonForm(name);
	if (!frm)
		throw (std::bad_alloc());
	return (frm);
}

static	AForm	*createShrubbery(const std::string name)
{
	AForm	*frm = NULL;

	frm = new PresidentialPardonForm(name);
	if (!frm)
		throw (std::bad_alloc());
	return (frm);
}

AForm	*Intern::makeForm(const std::string name_of_form, std::string form_target) const
{
	AForm	*(func)
	try
	{

	}
	catch (std::exception &ex)
	{

	}
}
