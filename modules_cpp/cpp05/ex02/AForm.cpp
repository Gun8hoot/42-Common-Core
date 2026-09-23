
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void) : _name("Unnamed form"), _sign_minimal_grade(150), _execute_minimal_grade(150), _is_signed(false) {}
AForm::AForm(const std::string &name) : _name(name), _sign_minimal_grade(150), _execute_minimal_grade(150), _is_signed(false) {}
AForm::AForm(const std::string &name, int sign_grade, int exec_grade)
    : _name(name), _sign_minimal_grade(sign_grade), _execute_minimal_grade(exec_grade), _is_signed(false)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm &cpy)
    : _name(cpy._name), _sign_minimal_grade(cpy._sign_minimal_grade),
      _execute_minimal_grade(cpy._execute_minimal_grade), _is_signed(cpy._is_signed) {}
AForm &AForm::operator=(const AForm &cpy)
{
    if (this != &cpy) _is_signed = cpy._is_signed;
    return *this;
}
AForm::~AForm(void) {}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _sign_minimal_grade)
        throw GradeTooLowException();
    _is_signed = true;
}

const std::string &AForm::getName(void) const { return _name; }
bool AForm::getIs_Signed(void) const { return _is_signed; }
int AForm::getSign_Minimal_Grade(void) const { return _sign_minimal_grade; }
int AForm::getExecute_Minimal_Grade(void) const { return _execute_minimal_grade; }

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return "The grade is too high";
}
const char *AForm::GradeTooLowException::what(void) const throw()
{
    return "The grade is too low";
}
const char *AForm::NotSignedException::what(void) const throw()
{
    return "The form is not signed";
}

std::ostream &operator<<(std::ostream &os, const AForm &data)
{
    os << "The form \"" << data.getName() << "\" need at least a grade <= at "
       << data.getSign_Minimal_Grade() << " to be signed and "
       << data.getExecute_Minimal_Grade() << " to be executed.";
    return os;
}
