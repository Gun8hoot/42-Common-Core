
#pragma once

#include <string>
#include <ostream>
#include <exception>
#include "AForm.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		class GradeTooHighException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("The grade is too high!");
			};
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char *what(void) const throw()
			{
				return ("The grade is too low!");
			};
		};

		~Bureaucrat(void);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int new_grade);
		Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat &cpy);

		const std::string	getName(void) const;
		int					getGrade(void) const;

		void				setGrade(int newGrade);
		void				signForm(AForm &form);

		Bureaucrat operator++(void);	// PRE INCREASE
		Bureaucrat operator++(int);		// POST INCREASE
		Bureaucrat operator--(void);	// PRE DECREASE
		Bureaucrat operator--(int);		// PRE DECREASE

		void		executeForm(AForm const & form) const;
};

std::ostream &operator<<(std::ostream& os, Bureaucrat& data);
