
# pragma once

#include "AForm.hpp"

class	Intern
{
	public:
		// -- CONSTRUCTOR --
		Intern(void);
		Intern(const Intern &cpy);
		Intern	&operator=(const Intern &cpy);
		~Intern(void);

		// -- MEMBER FUNCTION --
		AForm	&makeForm(const std::string name_of_form, std::string form_target) const;
};
