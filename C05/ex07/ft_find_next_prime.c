#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (nb <= 1)
		return (0);
	while (i <= nb)
	{
		if ((nb%i) == 0)
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return(0);
}

int	ft_find_next_prime(int nb)
{
	int found = 0;

	while (found != 1)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (0);
	
}

int	main(void)
{
	int	nb = 62;
	printf("Prime number %d >= %d", nb, ft_find_next_prime(nb));
	return (0);
}

