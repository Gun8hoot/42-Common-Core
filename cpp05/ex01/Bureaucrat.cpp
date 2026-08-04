#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <exception>
# include <iostream>

// --- CONSTRUCTOR ---
Bureaucrat::~Bureaucrat(void) { this->_grade = 150; }

Bureaucrat::Bureaucrat(const std::string name) : _name(name), _grade(150) { ; }

Bureaucrat::Bureaucrat(const Bureaucrat &cpy)
    : _name(cpy._name), _grade(cpy._grade) { ; }

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy)
{
	this->_grade = cpy._grade;
	return (*this);
}

// --- GETTER/SETTER ---
const std::string Bureaucrat::getName(void) { return (this->_name); }

int Bureaucrat::getGrade(void) { return (this->_grade); }

void Bureaucrat::setGrade(int newGrade)
{
	#ifdef DEBUG
	std::cout << "[-] DEBUG MODE : User " << this->_name << " want change his grade from " << this->_grade << " to " << newGrade << std::endl;
	#endif // DEBUG

	if (newGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (newGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
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

void				Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &except)
	{
		std::cout << this->_name << " couldn’t sign " << form.getName() << " because " << except.what() << ".";
	}
}
