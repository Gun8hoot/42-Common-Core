
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("Presidential", PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential", PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy)
    : AForm(cpy), _target(cpy._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cpy)
{
    if (this != &cpy)
    {
        AForm::operator=(cpy);
        _target = cpy._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!getIs_Signed())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecute_Minimal_Grade())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
