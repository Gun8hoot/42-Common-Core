
#pragma once

# include <string>
# include "AForm.hpp"

# define SHRUBBERY_SIGN_GRADE 145
# define SHRUBBERY_EXEC_GRADE 137

class Bureaucrat;

class	ShrubberyCreationForm : public AForm
{
	private:
		const std::string				_target;
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
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		ShrubberyCreationForm operator=(const ShrubberyCreationForm &cpy);
		~ShrubberyCreationForm(void);

		// -- MEMBER FUNCTION --
		void							execute(Bureaucrat const & executor) const;
};
