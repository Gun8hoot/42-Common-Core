#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <exception>
# include <iostream>

// --- CONSTRUCTOR ---
Bureaucrat::~Bureaucrat(void) { ; }

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150) { ; }

Bureaucrat::Bureaucrat(const std::string name, int new_grade) : _name(name)
{
	if (new_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (new_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade = new_grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
    : _name(cpy._name), _grade(cpy._grade) { ; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
	this->_grade = cpy._grade;
	return (*this);
}

// --- GETTER/SETTER ---
const std::string Bureaucrat::getName(void) const { return (this->_name); }

int Bureaucrat::getGrade(void) const { return (this->_grade); }

void Bureaucrat::setGrade(int newGrade)
{
	#ifdef DEBUG
	std::cout << "[-] DEBUG MODE : User " << this->_name << " want change his grade from " << this->_grade << " to " << newGrade << std::endl;
	#endif // DEBUG

	if (newGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (newGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = newGrade;

	#ifdef DEBUG
	std::cout << "[-] DEBUG MODE : " << this->_name << " change his grade to " << newGrade << std::endl;
	#endif // DEBUG
}

// --- OPERATOR OVERIDE ---
std::ostream &operator<<(std::ostream& os, Bureaucrat& data)
{
	os << data.getName() << ", bureaucrat grade " << data.getGrade() << std::endl;
	return (os);
};

Bureaucrat	Bureaucrat::operator++(void)
{
	if (_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
	#ifdef DEBUG
	std::cout <<	"Pre increase for " << this->_name <<
					" from " << this->_grade - 1 <<
					" to " << this->_grade << std::endl;
	#endif
	return (*this);
}

Bureaucrat	Bureaucrat::operator++(int)
{
	Bureaucrat	tmp = *this;

	if (_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
	#ifdef DEBUG
	std::cout <<	"Post increase for " << this->_name <<
					" from " << this->_grade - 1 <<
					" to " << this->_grade << std::endl;
	#endif
	return (tmp);
}

Bureaucrat	Bureaucrat::operator--(void)
{
	if (_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
	#ifdef DEBUG
	std::cout <<	"Pre decrease for " << this->_name <<
					" from " << this->_grade + 1 <<
					" to " << this->_grade << std::endl;
	#endif
	return (*this);
}

Bureaucrat	Bureaucrat::operator--(int)
{
	Bureaucrat	tmp = *this;

	if (_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
	#ifdef DEBUG
	std::cout <<	"Post decrease for " << this->_name <<
					" from " << this->_grade + 1 <<
					" to " << this->_grade << std::endl;
	#endif
	return (tmp);
}

void				Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &except)
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << except.what() << "." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
	}
	catch (std::exception &ex)
	{
		std::cerr << "Failed to execute form " << form.getName() << " because " << ex.what() << std::endl;
	}
}
