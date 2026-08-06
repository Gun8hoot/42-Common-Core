
#pragma once

# include "AForm.hpp"

# define ROBOTOMY_SIGN 72
# define ROBOTOMY_EXEC 45

class RobotomyRequestForm : public AForm
{
	public:
		void	execute(Bureaucrat const &executor) const;
		void	beSigned(Bureaucrat &signatory);
};
