
#pragma once

#include <string>
#include <ostream>
#include <exception>

class Bureaucrat
{
private:
    const std::string _name;
    int               _grade;

public:
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

    Bureaucrat(void);
    Bureaucrat(const std::string &name);
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &cpy);
    Bureaucrat &operator=(const Bureaucrat &cpy);
    ~Bureaucrat(void);

    const std::string &getName(void) const;
    int                getGrade(void) const;

    void incrementGrade(void);
    void decrementGrade(void);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &data);
