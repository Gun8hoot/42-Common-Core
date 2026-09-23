#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

#include <fstream>
#include <iostream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("Shrubbery", SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXEC_GRADE), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("Shrubbery", SHRUBBERY_SIGN_GRADE, SHRUBBERY_EXEC_GRADE), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cpy)
    : AForm(cpy), _target(cpy._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cpy)
{
    if (this != &cpy)
    {
        AForm::operator=(cpy);
        _target = cpy._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getIs_Signed())
        throw AForm::NotSignedException();
    if (executor.getGrade() > getExecute_Minimal_Grade())
        throw AForm::GradeTooLowException();

    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open file");
    file << "       ###\n"
            "      #o###\n"
            "    #####o###\n"
            "   #o#\\#|#/###\n"
            "    ###\\|/#o#\n"
            "     # }|{ #\n"
            "       }|{\n";
    file.close();
    std::cout << "Tree \"" << _target << "\" has been planted..." << std::endl;
}
