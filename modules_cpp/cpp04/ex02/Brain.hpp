
#pragma once
#include <string>
#include <cstring>
#include <iostream>

class	Brain
{
	private:
		std::string	ideas[100];
	public:
		std::string *getIdea(void);
		void		setIdea(std::string newIdea, int N);

		Brain(void);
		~Brain(void);
		Brain(const Brain &cpy);
		Brain &operator=(const Brain &cpy);
};
