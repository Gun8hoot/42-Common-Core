#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("Robotomy", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("Robotomy", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cpy)
    : AForm(cpy), _target(cpy._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cpy)
{
    if (this != &cpy)
    {
        AForm::operator=(cpy);
        _target = cpy._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!getIs_Signed())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecute_Minimal_Grade())
        throw AForm::GradeTooLowException();

    std::srand(std::time(NULL));
    std::cout << ">>> drilling_noises.wav <<<" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized!" << std::endl;
    else
        std::cout << _target << " failed to be robotomized!" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget(void) const { return _target; }
