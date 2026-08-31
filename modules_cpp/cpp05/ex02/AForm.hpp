
#pragma once

#include <string>

class Bureaucrat;

class	AForm
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
		AForm(void);
		AForm(const std::string name);
		AForm(const std::string name, const int _sign_grade, const int _exec_grade);
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &cpy);
		virtual ~AForm(void) = 0;

		// --- MEMBER FUNCTION ---
		void							beSigned(Bureaucrat &bureaucrat);
		virtual void					execute(Bureaucrat const & executor) const = 0;

		// --- GETTER ---
		const std::string				getName(void) const;
		bool							getIs_Signed(void) const;
		int								getSign_Minimal_Grade(void) const;
		int								getExecute_Minimal_Grade(void) const;

};

std::ostream &operator<<(std::ostream& os, AForm& data);
