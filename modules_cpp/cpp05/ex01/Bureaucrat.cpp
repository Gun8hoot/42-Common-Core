
#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

// --- CONSTRUCTORS / DESTRUCTOR ---
Bureaucrat::Bureaucrat(void) : _name("Unknown"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
    : _name(cpy._name), _grade(cpy._grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
    if (this != &cpy)
        _grade = cpy._grade;
    return *this;
}

Bureaucrat::~Bureaucrat(void) {}

// --- GETTERS ---
const std::string &Bureaucrat::getName(void) const
{
    return _name;
}

int Bureaucrat::getGrade(void) const
{
    return _grade;
}

// --- GRADE MODIFIERS ---
void Bureaucrat::incrementGrade(void)
{
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade(void)
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    ++_grade;
}

// --- SIGN FORM ---
void Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &except)
    {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << except.what() << "." << std::endl;
    }
}

// --- OSTREAM ---
std::ostream &operator<<(std::ostream &os, const Bureaucrat &data)
{
    os << data.getName() << ", bureaucrat grade " << data.getGrade();
    return os;
}

// --- EXCEPTIONS ---
const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "The grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "The grade is too low!";
}
