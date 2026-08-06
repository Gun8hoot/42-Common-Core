
#pragma once

# include <string>
# include "AForm.hpp"

# define PRESIDENTIAL_SIGN_GRADE 25
# define PRESIDENTIAL_EXEC_GRADE 5

class Bureaucrat;

class	PresidentialPardonForm : public AForm
{
	private:
		const std::string	_name;
		bool							_is_signed;
		int								_sign_minimal_grade;
		int								_execute_minimal_grade;

	public:
		// -- CUSTOM EXCEPTIONS --
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return ("his grade is too high");
				};
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return ("his grade is too low");
				};
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return ("the form didnt have been signed yet");
				};
		};

		// -- CONSTRUCTOR --
		PresidentialPardonForm(std::string name);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);
		PresidentialPardonForm operator=(const PresidentialPardonForm &cpy);
		~PresidentialPardonForm(void);

		// -- MEMBER FUNCTION --
		void							execute(Bureaucrat const & executor) const;
};
