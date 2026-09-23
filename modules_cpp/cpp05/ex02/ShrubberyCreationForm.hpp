#pragma once

#include <string>
#include "AForm.hpp"

#define SHRUBBERY_SIGN_GRADE 145
#define SHRUBBERY_EXEC_GRADE 137

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
private:
    std::string _target;

public:
    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);
    ~ShrubberyCreationForm(void);

    void execute(Bureaucrat const &executor) const;
};
