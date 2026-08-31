#include "includes/main.hpp"

int	stoi(std::string toConvert, int &num)
{
	int i = 0;

	num = 0;
	if (toConvert[0] == '-')
	{
		num = -1;
		return (-1);
	}
	while (toConvert [i] >= '\t' && toConvert [i] <= '\r')
		i++;
	while (toConvert[i] >= '0' && toConvert[i] <= '9')
	{
		num = num * 10 + (toConvert[i] - '0');
		i++;
	}
	return (num);
}
