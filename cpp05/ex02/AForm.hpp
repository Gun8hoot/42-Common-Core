
#pragma once

#include <string>

class Bureaucrat;

class	AForm
{
	protected:
		const std::string	_name;
		bool				_is_signed;
		int					_sign_minimal_grade;
		int					_execute_minimal_grade;

		// -- CONSTRUCTOR --
		AForm(const std::string name, int _sign_grade, int _exec_grade);
		AForm(const AForm &cpy);
		AForm &operator=(const AForm &cpy);

		// -- SETTER --
		void							setExecute_Minimal_Grade(int _new_grade);
		void							setSign_Minimal_Grade(int _new_grade);

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
	public:

		// -- GETTER --
		int								getExecute_Minimal_Grade(void) const;
		int								getSign_Minimal_Grade(void) const;
		bool							getIs_Signed(void) const;
		const std::string				getName(void) const;

		// -- OVERRIDE FUNCTION --
		virtual			~AForm(void) = 0;
		virtual void	execute(Bureaucrat const &executor) const = 0;
		virtual void	beSigned(Bureaucrat &signatory);

};
