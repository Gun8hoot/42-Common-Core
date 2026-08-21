
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// --- CONSTRUCTOR / DESTRUCTOR ---
AForm::AForm(void) : _name("Unamed form"), _sign_minimal_grade(150), _execute_minimal_grade(150), _is_signed(false) {;}
AForm::AForm(const std::string name) : _name(name), _sign_minimal_grade(150), _execute_minimal_grade(150), _is_signed(false) { ; }
AForm::AForm(const std::string name, const int _sign_grade, const int _exec_grade)
	:	_name(name),
		_sign_minimal_grade(_sign_grade),
		_execute_minimal_grade(_exec_grade),
		_is_signed(false)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw (AForm::GradeTooHighException());
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw (AForm::GradeTooLowException());
}
AForm::AForm(const AForm &cpy)
	:	_name(cpy._name),
	_sign_minimal_grade(cpy._sign_minimal_grade),
	_execute_minimal_grade(cpy._execute_minimal_grade),
	_is_signed(cpy._is_signed)
{ ; }
AForm	&AForm::operator=(const AForm &cpy)
{
	if (this != &cpy)
		this->_is_signed = cpy._is_signed;
	return (*this);
}
AForm::~AForm(void) { ; }

// --- MEMBER FUNCTION ---
void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_minimal_grade)
		throw (AForm::GradeTooLowException());
	this->_is_signed = true;
}

// --- GETTER ---
const std::string	AForm::getName(void) const { return (this->_name); }
bool				AForm::getIs_Signed(void) const { return (this->_is_signed); }
int					AForm::getSign_Minimal_Grade(void) const { return (this->_sign_minimal_grade); }
int					AForm::getExecute_Minimal_Grade(void) const { return (this->_execute_minimal_grade); }

// --- EXCEPTION ---
const char *AForm::GradeTooHighException::what() const throw() { return ("The grade is too high"); };
const char *AForm::GradeTooLowException::what() const throw() { return ("The grade is too low"); };

// --- OSTREAM OVERLOAD ---
std::ostream &operator<<(std::ostream& os, AForm& data)
{
	os	<< "The form \"" << data.getName() << "\" need at least a grade <= at "
		<< data.getSign_Minimal_Grade() << " to be signed and "
		<< data.getExecute_Minimal_Grade() << " to be executed.";
	return (os);
}
