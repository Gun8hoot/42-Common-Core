
#pragma once

# include <string>
# include "AForm.hpp"

# define ROBOTOMY_SIGN_GRADE 72
# define ROBOTOMY_EXEC_GRADE 45

class Bureaucrat;

class	RobotomyRequestForm : public AForm
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
		RobotomyRequestForm(std::string name);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm operator=(const RobotomyRequestForm &cpy);
		~RobotomyRequestForm(void);

		// -- MEMBER FUNCTION --
		void							execute(Bureaucrat const & executor) const;
};
