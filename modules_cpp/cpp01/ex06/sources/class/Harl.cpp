
#include "includes/class/harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
}

void Harl::complain(std::string level)
{
	std::size_t	i = 0;
	std::string levelType[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string levelMsg[4] = {
	 "love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n",
		"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n",
		"I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month\n",
		"This is unacceptable! I want to speak to the manager now.\n"
	};
	void	(Harl::*level_function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	Harl	*levelCall = this;

	while (i < 4)
	{
		if (levelType[i].compare(level) == 0)
			break;
		i++;
	}
	switch (i)
	{
		case 0:		// DEBUG
			(levelCall->*level_function[0])();
			std::cout << levelMsg[0] << std::endl;
			// fallthrough
		case 1:		// INFO
			(levelCall->*level_function[1])();
			std::cout << levelMsg[1] << std::endl;
			// fallthrough
		case 2:		// WARNING
			(levelCall->*level_function[2])();
			std::cout << levelMsg[2] << std::endl;
			// fallthrough
		case 3:		// ERROR
			(levelCall->*level_function[3])();
			std::cout << levelMsg[3] << std::endl;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]\n";
			break;
	}
}
