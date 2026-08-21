
#include "Form.hpp"
#include "Bureaucrat.hpp"

// --- CONSTRUCTOR / DESTRUCTOR ---
Form::Form(void) : _name("Unamed form"), _sign_minimal_grade(150), _execute_minimal_grade(150), _is_signed(false) {;}
Form::Form(const std::string name) : _name(name), _sign_minimal_grade(150), _execute_minimal_grade(150), _is_signed(false) { ; }
Form::Form(const std::string name, const int _sign_grade, const int _exec_grade)
	:	_name(name),
		_sign_minimal_grade(_sign_grade),
		_execute_minimal_grade(_exec_grade),
		_is_signed(false)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw (Form::GradeTooHighException());
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw (Form::GradeTooLowException());
}
Form::Form(const Form &cpy)
	:	_name(cpy._name),
	_sign_minimal_grade(cpy._sign_minimal_grade),
	_execute_minimal_grade(cpy._execute_minimal_grade),
	_is_signed(cpy._is_signed)
{ ; }
Form	&Form::operator=(const Form &cpy)
{
	if (this != &cpy)
		this->_is_signed = cpy._is_signed;
	return (*this);
}
Form::~Form(void) { ; }

// --- MEMBER FUNCTION ---
void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_minimal_grade)
		throw (Form::GradeTooLowException());
	this->_is_signed = true;
}

// --- GETTER ---
const std::string	Form::getName(void) { return (this->_name); }
bool				Form::getIs_Signed(void) { return (this->_is_signed); }
int					Form::getSign_Minimal_Grade(void) { return (this->_sign_minimal_grade); }
int					Form::getExecute_Minimal_Grade(void) { return (this->_execute_minimal_grade); }

// --- EXCEPTION ---
const char *Form::GradeTooHighException::what() const throw() { return ("The grade is too high"); };
const char *Form::GradeTooLowException::what() const throw() { return ("The grade is too low"); };

// --- OSTREAM OVERLOAD ---
std::ostream &operator<<(std::ostream& os, Form& data)
{
	os	<< "The form \"" << data.getName() << "\" need at least a grade <= at "
		<< data.getSign_Minimal_Grade() << " to be signed and "
		<< data.getExecute_Minimal_Grade() << " to be executed."
		<< std::endl;
	return (os);
}
