
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <iostream>

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > ROBOTOMY_EXEC)
		throw (RobotomyRequestForm::GradeTooLowException());
	std::cout << ">>> drilling_noise.wav <<<" << std::endl;
	if (rand() % 2 == 0)
		std::cout << "[+] " << executor.getName() << " has been robotomized!" << std::endl;
	else
		std::cout << "[!] " << "The robotomy failed on " << executor.getName() << std::endl;
}

void	RobotomyRequestForm::beSigned(Bureaucrat &signatory)
{
	if (signatory.getGrade() > ROBOTOMY_SIGN)
		throw (RobotomyRequestForm::GradeTooLowException());
	this->_is_signed = true;
}
