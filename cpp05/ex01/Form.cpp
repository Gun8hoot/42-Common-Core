
#include "Form.hpp"
#include "Bureaucrat.hpp"

// -- CONSTRUCTOR --
Form::Form(const std::string name) : _name(name), _is_signed(false), _execute_minimal_grade(150), _sign_minimal_grade(150) { ; }

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

const std::string	Form::getName(void)
{
	return (this->_name);
}
