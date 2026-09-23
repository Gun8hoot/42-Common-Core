
#include "Form.hpp"
#include "Bureaucrat.hpp"

// --- CONSTRUCTORS / DESTRUCTOR ---
Form::Form(void)
    : _name("Unnamed form"),
      _sign_minimal_grade(150),
      _execute_minimal_grade(150),
      _is_signed(false) {}

Form::Form(const std::string &name)
    : _name(name),
      _sign_minimal_grade(150),
      _execute_minimal_grade(150),
      _is_signed(false) {}

Form::Form(const std::string &name, int sign_grade, int exec_grade)
    : _name(name),
      _sign_minimal_grade(sign_grade),
      _execute_minimal_grade(exec_grade),
      _is_signed(false)
{
    if (sign_grade < 1 || exec_grade < 1)
        throw GradeTooHighException();
    if (sign_grade > 150 || exec_grade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &cpy)
    : _name(cpy._name),
      _sign_minimal_grade(cpy._sign_minimal_grade),
      _execute_minimal_grade(cpy._execute_minimal_grade),
      _is_signed(cpy._is_signed) {}

Form &Form::operator=(const Form &cpy)
{
    if (this != &cpy)
        _is_signed = cpy._is_signed;
    return *this;
}

Form::~Form(void) {}

// --- MEMBER FUNCTION ---
void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _sign_minimal_grade)
        throw GradeTooLowException();
    _is_signed = true;
}

// --- GETTERS ---
const std::string &Form::getName(void) const
{
    return _name;
}

bool Form::getIs_Signed(void) const
{
    return _is_signed;
}

int Form::getSign_Minimal_Grade(void) const
{
    return _sign_minimal_grade;
}

int Form::getExecute_Minimal_Grade(void) const
{
    return _execute_minimal_grade;
}

// --- EXCEPTIONS ---
const char *Form::GradeTooHighException::what(void) const throw()
{
    return "The grade is too high";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
    return "The grade is too low";
}

// --- OSTREAM ---
std::ostream &operator<<(std::ostream &os, const Form &data)
{
    os << "The form \"" << data.getName() << "\" need at least a grade <= at "
       << data.getSign_Minimal_Grade() << " to be signed and "
       << data.getExecute_Minimal_Grade() << " to be executed.";
    return os;
}
