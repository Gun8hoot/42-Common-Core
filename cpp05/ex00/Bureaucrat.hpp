
#pragma once

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		// -- EXCEPTIONS --
		class GradeTooHighException : public std::exception
		{
			virtual const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what(void) const throw();
		};

		// -- CONSTRUCTOR --
		Bureaucrat(void); // DEFAULT CONSTRUCTOR
		Bureaucrat(const Bureaucrat &cpy); // COPY CONSTRUCTOR
		Bureaucrat &operator=(const Bureaucrat &cpy); // COPY ASSIGNEMENTS CONSTRUCTOR
		~Bureaucrat(void); // DESTRUCTOR
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, const int grade);

		const std::string	getName(void);

		int					getGrade(void);
		void				setGrade(int newGrade);

		Bureaucrat operator--(void);	// PRE DECREASE
		Bureaucrat operator--(int);		// POST DECREASE
		Bureaucrat operator++(void);	// PRE INCREASE
		Bureaucrat operator++(int);		// POST INCREASE

};

std::ostream &operator<<(std::ostream& os, Bureaucrat& data);
