
#pragma once

#include <string>
#include <exception>
#include <ostream>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    const int         _sign_minimal_grade;
    const int         _execute_minimal_grade;
    bool              _is_signed;

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

    Form(void);
    Form(const std::string &name);
    Form(const std::string &name, int sign_grade, int exec_grade);
    Form(const Form &cpy);
    Form &operator=(const Form &cpy);
    ~Form(void);

    void beSigned(const Bureaucrat &bureaucrat);

    const std::string &getName(void) const;
    bool               getIs_Signed(void) const;
    int                getSign_Minimal_Grade(void) const;
    int                getExecute_Minimal_Grade(void) const;
};

std::ostream &operator<<(std::ostream &os, const Form &data);
