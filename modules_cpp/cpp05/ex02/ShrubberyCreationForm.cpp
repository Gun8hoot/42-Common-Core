
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>
#include <fstream>

// -- CONSTRUCTOR --
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("Shrubbery", SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXEC_GRADE)
		, _target(target)
		, _is_signed(false)
		, _sign_minimal_grade(SHRUBBERY_SIGN_GRADE)
		, _execute_minimal_grade(SHRUBBERY_EXEC_GRADE)
		{;}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy) : AForm(cpy), _target(cpy._target)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy.getIs_Signed();
		this->_execute_minimal_grade = cpy.getExecute_Minimal_Grade();
		this->_sign_minimal_grade = cpy.getSign_Minimal_Grade();
	}
}
ShrubberyCreationForm	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy.getIs_Signed();
		this->_execute_minimal_grade = cpy.getExecute_Minimal_Grade();
		this->_sign_minimal_grade = cpy.getSign_Minimal_Grade();
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { ; }

// -- MEMBER FUNCTION --
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::fstream	file;

	if (this->getIs_Signed() == false)
		throw (ShrubberyCreationForm::NotSignedException());
	if (executor.getGrade() > this->_execute_minimal_grade)
		throw (ShrubberyCreationForm::GradeTooLowException());

	file.exceptions(std::fstream::badbit | std::fstream::failbit);
	file.open((_target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
	file		<< "       ###\n"
				<< "      #o###\n"
				<< "    #####o###\n"
				<< "   #o#\\#|#/###\n"
				<< "    ###\\|/#o#\n"
				<< "     # }|{ #\n"
				<< "       }|{\n";
	file.close();
	std::cout << "Tree \"" << this->_target << "\" have been planted..." << std::endl;
}
