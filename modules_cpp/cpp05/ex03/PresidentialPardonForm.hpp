#pragma once

#include <string>
#include "AForm.hpp"

#define PRESIDENTIAL_SIGN_GRADE 25
#define PRESIDENTIAL_EXEC_GRADE 5

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
private:
    std::string _target;

public:
    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &cpy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);
    ~PresidentialPardonForm(void);

    void execute(Bureaucrat const &executor) const;
};
