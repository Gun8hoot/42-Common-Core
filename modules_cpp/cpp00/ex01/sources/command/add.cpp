
#include "includes/main.hpp"

//     Index      f_name     l_name     nick
//	+----------+----------+----------+---------+
//	|          |          |          |		   |
//	+----------+----------+----------+---------+
//	|          |          |          |         |
//	+----------+----------+----------+---------+
//	|          |          |          |         |
//	+----------+----------+----------+---------+

static void  append_contact(PhoneBook &phonebook)
{
	Contact tmp;

	tmp.adding_contact();
	for (int i = 0; i <= phonebook.recorded - 2; i++)
	{
		phonebook.contact[i] = phonebook.contact[i + 1];
	}
	phonebook.contact[7] = tmp;
}

void  add(PhoneBook &phonebook)
{
	if (phonebook.recorded < 8)
	{
		phonebook.contact[phonebook.recorded].adding_contact();
		phonebook.recorded += 1;
	}
	else
		append_contact(phonebook);
}
