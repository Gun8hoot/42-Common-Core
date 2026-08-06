
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, int _sign_grade, int _exec_grade) : _name(name), _is_signed(false)
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw (AForm::GradeTooHighException());
	else if (_sign_grade > 150 || _exec_grade > 150)
		throw (AForm::GradeTooLowException());
	this->_sign_minimal_grade = _sign_grade;
	this->_execute_minimal_grade = _exec_grade;
}

AForm::AForm(const AForm &cpy) : _name(cpy._name)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy.getIs_Signed();
		this->_execute_minimal_grade = cpy.getExecute_Minimal_Grade();
		this->_sign_minimal_grade = cpy.getSign_Minimal_Grade();
	}
}

AForm &AForm::operator=(const AForm &cpy)
{
	if (this != &cpy)
	{
		this->_is_signed = cpy.getIs_Signed();
		this->_execute_minimal_grade = cpy.getExecute_Minimal_Grade();
		this->_sign_minimal_grade = cpy.getSign_Minimal_Grade();
	}
	return (*this);
};

AForm::~AForm(void) {;};

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
