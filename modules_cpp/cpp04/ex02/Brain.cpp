#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Calling brain constructor\n";
	std::memset(&this->ideas, '\0', sizeof(this->ideas));
}

Brain::Brain(const Brain &cpy)
{
	std::cout << "Calling brain constructor\n";
	if (this != &cpy)
		std::memcpy(&this->ideas, cpy.ideas, sizeof(this->ideas));
}

Brain	&Brain::operator=(const Brain &cpy)
{
	std::cout << "Calling Brain constructor\n";
	if (this != &cpy)
		std::memcpy(&this->ideas, cpy.ideas, sizeof(this->ideas));
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Calling Brain destructor\n";
	std::memset(&this->ideas, '\0', sizeof(this->ideas));
}

void	Brain::setIdea(std::string newIdea, int N)
{
	if (newIdea.empty() || N < 0 || N > 99)
	{
		std::cout << "Failed to write \"" << newIdea << "\" at place " << N << "\n";
		return;
	}
	this->ideas[N] = newIdea;
	return;
}

std::string *Brain::getIdea(void)
{
	return (this->ideas);
}
