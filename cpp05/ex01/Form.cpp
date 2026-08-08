
#include "Form.hpp"
#include "Bureaucrat.hpp"

// -- CONSTRUCTOR --

Form::Form(const std::string name) : _name(name), _is_signed(false), _sign_minimal_grade(150), _execute_minimal_grade(150) { ; }

Form::Form(const std::string name, int _sign_grade, int _exec_grade) : _name(name)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw (Form::GradeTooHighException());
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw (Form::GradeTooLowException());
	this->_sign_minimal_grade = _sign_grade;
	this->_execute_minimal_grade = _exec_grade;
}

Form::~Form(void) { ; }

Form::Form(const Form &cpy)
{
	if (this != &cpy)
	{
		this->_execute_minimal_grade = cpy._execute_minimal_grade;
		this->_sign_minimal_grade = cpy._sign_minimal_grade;
		this->_is_signed = cpy._is_signed;
	}
}

Form	&Form::operator=(const Form &cpy)
{
	if (this != &cpy)
	{
		this->_execute_minimal_grade = cpy._execute_minimal_grade;
		this->_sign_minimal_grade = cpy._sign_minimal_grade;
		this->_is_signed = cpy._is_signed;
	}
	return (*this);
}

// -- MEMBER FUNCTION --
void	Form::beSigned(Bureaucrat &signatory)
{
	if (signatory.getGrade() > this->_sign_minimal_grade)
		throw (Form::GradeTooLowException());
	this->_is_signed = true;
}

// -- GETTER --
const std::string	Form::getName(void)
{
	return (this->_name);
}

bool	Form::getIs_Signed(void)
{
	return (this->_is_signed);
}

int		Form::getSign_Minimal_Grade(void)
{
	return (this->_sign_minimal_grade);
}

int		Form::getExecute_Minimal_Grade(void)
{
	return (this->_execute_minimal_grade);
}

// -- SETTER --
void	Form::setSign_Minimal_Grade(int _new_grade)
{
	if (_new_grade < 1)
		throw (Form::GradeTooHighException());
	else if (_new_grade > 150)
		throw (Form::GradeTooLowException());
	this->_sign_minimal_grade = _new_grade;
}

void	Form::setExecute_Minimal_Grade(int _new_grade)
{
	if (_new_grade < 1)
		throw (Form::GradeTooHighException());
	else if (_new_grade > 150)
		throw (Form::GradeTooLowException());
	this->_execute_minimal_grade = _new_grade;
}
