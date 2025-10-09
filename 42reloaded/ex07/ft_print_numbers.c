#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_numbers(void)
{
	char	j;
	j = '0';

	while (j <= '9')
	{
		ft_putchar(j);
		j++;
	}
}

// int main(void)
// {
// 	ft_print_numbers();
// }