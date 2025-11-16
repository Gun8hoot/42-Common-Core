#include "lib/push_swap.h"

void	del(void *content)
{
	if (content)
		free(content);
	
}

int	complexstring(char *av)
{
	size_t	i;
	size_t	j;
	t_list	*node;
	char	number[11];

	i = 0;
	j = 0;
	ft_memset(number, 0, 11);
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 0 && (av[i] != ' ' && av[i] != '-'))
			return(EXIT_FAILURE);
		else if ((ft_isdigit(av[i]) == 1 || av[i] == '-') && av[i] != ' ')
			number[j++] = av[i];
		if (av[i] == ' ' || av[i + 1] == '\0')
		{
			if (number[0] != '\0')
			{
				printf("%s\n", number);
				ft_memset(number, 0, 11);
				j = 0;
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	simplestring(char *av)
{
	size_t	i;
	size_t	j;
	char	number[11];


	i = 0;
	j = 0;
	ft_memset(number, 0, 11);
	while (av[i])
	{
		if (ft_isdigit(av[i]) == 0 && av[i] != '-')
			return (EXIT_FAILURE);
		number[i] = av[i];
		i++;
	}
	if (av[0] == '-' && av[1] == '\0')
		return(EXIT_FAILURE);
	printf("%s\n", number);
	return (EXIT_SUCCESS);
}

int	argv2lst(t_stacks *stack_a, int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			if (complexstring(av[i]) == 1)
				return (EXIT_FAILURE);
		}
		else
		{
			if (simplestring(av[i]) == 1)
				return (EXIT_FAILURE);

		}
		i++;
	}
	return (EXIT_SUCCESS);
}
