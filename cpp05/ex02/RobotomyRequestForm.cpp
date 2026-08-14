
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>

// -- CONSTRUCTOR --
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE)
		, _target(target)
		, _is_signed(false)
		, _sign_minimal_grade(ROBOTOMY_SIGN_GRADE)
		, _execute_minimal_grade(ROBOTOMY_EXEC_GRADE)
		{;}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy) : AForm(cpy)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy.getIs_Signed();
		this->_execute_minimal_grade = cpy.getExecute_Minimal_Grade();
		this->_sign_minimal_grade = cpy.getSign_Minimal_Grade();
	}
}
RobotomyRequestForm	RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy.getIs_Signed();
		this->_execute_minimal_grade = cpy.getExecute_Minimal_Grade();
		this->_sign_minimal_grade = cpy.getSign_Minimal_Grade();
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { ; }

// -- MEMBER FUNCTION --
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand(time(NULL));

	if (this->getIs_Signed() == false)
		throw (RobotomyRequestForm::NotSignedException());
	if (executor.getGrade() > this->_execute_minimal_grade)
		throw (RobotomyRequestForm::GradeTooLowException());

	std::cout << ">>> drilling_noises.wav <<<" << std::endl;

	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized!" << std::endl;
	else
		std::cout << this->_target << " failed to be robotomized!" << std::endl;
}
