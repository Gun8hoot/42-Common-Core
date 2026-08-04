
#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <stdexcept>
#include <iostream>

int main(void)
{
	Bureaucrat user("user");
	Bureaucrat user2("user2");

	Form			form1("Super amazing form");
	Form			form2("Form from nowhere");

	user.signForm(form1);

}
