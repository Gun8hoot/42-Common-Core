
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
		class GradeTooHighException : public std::exception
		{
			virtual const char *what(void) const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what(void) const throw();
		};
    Bureaucrat(void);
		~Bureaucrat(void);
		Bureaucrat(const std::string name);
    Bureaucrat(const std::string name, const int grade);
    Bureaucrat(const Bureaucrat &cpy);
		Bureaucrat &operator=(const Bureaucrat &cpy);

		const std::string	getName(void);

		int					getGrade(void);
		void				setGrade(int newGrade);

		Bureaucrat operator++(void);	// PRE INCREASE
		Bureaucrat operator++(int);		// POST INCREASE
		Bureaucrat operator--(void);	// PRE DECREASE
		Bureaucrat operator--(int);		// POST DECREASE

};

std::ostream &operator<<(std::ostream& os, Bureaucrat& data);
