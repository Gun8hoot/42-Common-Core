
# pragma once

#include "AForm.hpp"
#include <exception>

class	Intern
{
	public:
		class	InvalidFormType : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		// -- CONSTRUCTOR --
		Intern(void);
		Intern(const Intern &cpy);
		Intern	&operator=(const Intern &cpy);
		~Intern(void);

		// -- MEMBER FUNCTION --
		AForm	*makeForm(std::string form_type, const std::string target_of_form) const;
};
