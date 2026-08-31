
#pragma once

#include <string>

class Bureaucrat;

class	Form
{
	private:
		const std::string				_name;
		const int						_sign_minimal_grade;
		const int						_execute_minimal_grade;
		bool							_is_signed;

	public:
		// -- CUSTOM EXCEPTIONS --
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what(void) const throw();
		};

		// --- CONSTRUCTOR / DESTRUCTOR ---
		Form(void);
		Form(const std::string name);
		Form(const std::string name, const int _sign_grade, const int _exec_grade);
		Form(const Form &cpy);
		Form &operator=(const Form &cpy);
		~Form(void);

		// --- MEMBER FUNCTION ---
		void							beSigned(Bureaucrat &bureaucrat);		// Sign the form

		// --- GETTER ---
		const std::string				getName(void);
		bool							getIs_Signed(void);
		int								getSign_Minimal_Grade(void);
		int								getExecute_Minimal_Grade(void);

};

std::ostream &operator<<(std::ostream& os, Form& data);
