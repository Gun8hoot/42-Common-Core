#pragma once

#include <string>
#include "AForm.hpp"

#define ROBOTOMY_SIGN_GRADE 72
#define ROBOTOMY_EXEC_GRADE 45

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
		~RobotomyRequestForm(void);

		void execute(Bureaucrat const &executor) const;
		const std::string &getTarget(void) const;
};
