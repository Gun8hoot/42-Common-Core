
#include "AForm.hpp"
#include "Bureaucrat.hpp"

// -- CONSTRUCTOR --
AForm::AForm(const std::string name, int _sign_grade, int _exec_grade) : _name(name)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw (AForm::GradeTooHighException());
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw (AForm::GradeTooLowException());
	this->_sign_minimal_grade = _sign_grade;
	this->_execute_minimal_grade = _exec_grade;
}

AForm::~AForm(void) { ; }

AForm::AForm(const AForm &cpy)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy._is_signed;
		this->_sign_minimal_grade = cpy._sign_minimal_grade;
		this->_execute_minimal_grade = cpy._execute_minimal_grade;
	}
}

AForm	&AForm::operator=(const AForm &cpy)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy._is_signed;
		this->_sign_minimal_grade = cpy._sign_minimal_grade;
		this->_execute_minimal_grade = cpy._execute_minimal_grade;
	}
	return (*this);
}

// -- MEMBER FUNCTION --
void	AForm::beSigned(Bureaucrat &signatory)
{
	if (signatory.getGrade() > this->_sign_minimal_grade)
		throw (AForm::GradeTooLowException());
	this->_is_signed = true;
}

// -- GETTER --
const std::string	AForm::getName(void) const { return (this->_name); }

bool	AForm::getIs_Signed(void) const { return (this->_is_signed); }

int		AForm::getSign_Minimal_Grade(void) const { return (this->_sign_minimal_grade); }

int		AForm::getExecute_Minimal_Grade(void) const { return (this->_execute_minimal_grade); }

// -- SETTER --
void	AForm::setSign_Minimal_Grade(int _new_grade)
{
	if (_new_grade < 1)
		throw (AForm::GradeTooHighException());
	else if (_new_grade > 150)
		throw (AForm::GradeTooLowException());
	this->_sign_minimal_grade = _new_grade;
}

void	AForm::setExecute_Minimal_Grade(int _new_grade)
{
	if (_new_grade < 1)
		throw (AForm::GradeTooHighException());
	else if (_new_grade > 150)
		throw (AForm::GradeTooLowException());
	this->_execute_minimal_grade = _new_grade;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	return;
}
