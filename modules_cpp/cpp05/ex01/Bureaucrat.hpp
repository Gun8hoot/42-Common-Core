
#pragma once

#include <string>
#include <ostream>
#include <exception>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		int								_grade;

	public:
		// --- CUSTOM EXCEPTION ---
		class GradeTooHighException : public std::exception
		{
			virtual const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what(void) const throw();
		};

		// --- CONSTRUCTOR / DESTRUCTOR ---
		Bureaucrat(void);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int new_grade);

		Bureaucrat(const Bureaucrat &cpy);

		Bureaucrat &operator=(const Bureaucrat &cpy);

		~Bureaucrat(void);

		// --- GETTER / SETTER ---
		const std::string	getName(void);

		int					getGrade(void);
		void				setGrade(int newGrade);
		void				signForm(Form &form);

		// --- OPERATOR OVERLOADING ---
		Bureaucrat operator++(void);	// PRE INCREASE
		Bureaucrat operator++(int);		// POST INCREASE
		Bureaucrat operator--(void);	// PRE DECREASE
		Bureaucrat operator--(int);		// PRE DECREASE

};

// --- OSTREAM OVERLOAD ---
std::ostream &operator<<(std::ostream& os, Bureaucrat& data);
