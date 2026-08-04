
#pragma once

#include <string>

class Bureaucrat;

class	Form
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
					return ("The grade is too high.");
				};
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw()
				{
					return ("The grade is too low.");
				};
		};

		// -- CONSTRUCTOR --
		Form(std::string name);
		Form(const Form &cpy);
		Form &operator=(const Form &cpy);
		~Form(void);

		// -- GETTER/SETTER --
		void							beSigned(Bureaucrat &signatory);	// Sign the form
		const std::string	getName(void);

};
