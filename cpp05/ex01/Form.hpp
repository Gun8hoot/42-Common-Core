
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

		// -- CONSTRUCTOR --
		Form(const std::string name, int _sign_grade, int _exec_grade);
		Form(const std::string name);
		Form(const Form &cpy);
		Form &operator=(const Form &cpy);
		~Form(void);

		// -- MEMBER FUNCTION --
		void							beSigned(Bureaucrat &signatory);		// Sign the form

		// -- GETTER/SETTER --
		bool							getIs_Signed(void);
		int								getSign_Minimal_Grade(void);
		int								getExecute_Minimal_Grade(void);

		void							setSign_Minimal_Grade(int _new_grade);
		void							setExecute_Minimal_Grade(int _new_grade);

		const std::string	getName(void);

};
