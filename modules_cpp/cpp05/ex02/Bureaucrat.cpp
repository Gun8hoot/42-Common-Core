
#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(void) : _name("Unknown"), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(150) {}
Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1) throw GradeTooHighException();
    if (_grade > 150) throw GradeTooLowException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy._name), _grade(cpy._grade) {}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
    if (this != &cpy) _grade = cpy._grade;
    return *this;
}
Bureaucrat::~Bureaucrat(void) {}

const std::string &Bureaucrat::getName(void) const { return _name; }
int Bureaucrat::getGrade(void) const { return _grade; }

void Bureaucrat::incrementGrade(void)
{
    if (_grade - 1 < 1) throw GradeTooHighException();
    --_grade;
}
void Bureaucrat::decrementGrade(void)
{
    if (_grade + 1 > 150) throw GradeTooLowException();
    ++_grade;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << _name << " couldn't sign " << form.getName()
                  << " because " << e.what() << "." << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << _name << " couldn't execute " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &data)
{
    os << data.getName() << ", bureaucrat grade " << data.getGrade();
    return os;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
    return "The grade is too high!";
}
const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
    return "The grade is too low!";
}
