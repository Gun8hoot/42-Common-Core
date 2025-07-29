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
//		printf("%d, ", nb/i);
		if ((nb%i) == 0)
			count++;
		i++;
	}
	if (count == 2)
		return (1);
	return(0);
}

int	main(void)
{
	int	nb = 1;

	while (nb < 100)
	{
		if (ft_is_prime(nb) == 1)
			printf("%d is prime\n", nb);
		else
			printf("%d is not prime\n", nb);
		nb++;
	}

}

