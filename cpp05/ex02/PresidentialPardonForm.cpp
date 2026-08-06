
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <fstream>

// -- CONSTRUCTOR --
PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm(name, PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE)
		, _name(name)
		, _is_signed(false)
		, _sign_minimal_grade(PRESIDENTIAL_SIGN_GRADE)
		, _execute_minimal_grade(PRESIDENTIAL_EXEC_GRADE)
		{;}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) : AForm(cpy), _name(cpy._name)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy.getIs_Signed();
		this->_execute_minimal_grade = cpy.getExecute_Minimal_Grade();
		this->_sign_minimal_grade = cpy.getSign_Minimal_Grade();
	}
}
PresidentialPardonForm	PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy.getIs_Signed();
		this->_execute_minimal_grade = cpy.getExecute_Minimal_Grade();
		this->_sign_minimal_grade = cpy.getSign_Minimal_Grade();
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) { ; }

// -- MEMBER FUNCTION --
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIs_Signed() == false)
		throw (PresidentialPardonForm::NotSignedException());
	if (executor.getGrade() > this->_execute_minimal_grade)
		throw (PresidentialPardonForm::GradeTooLowException());
	std::cout << executor.getName() << " have been pardoned by Zaphod Beeblebrox." << std::endl;
}
