#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	char	j;
	j = 'a';

	while (j <= 'z')
	{
		ft_putchar(j);
		j++;
	}
}

// int main(void)
// {
// 	ft_print_alphabet();
// }