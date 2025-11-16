#include "lib/push_swap.h"

void	del(void *content)
{
	if (content)
		free(content);
	
}

int	complexstring(char *av, t_list *head)
{
	size_t	i;
	size_t	j;
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
				//ft_lstadd_back(&head, ft_lstnew((int)ft_atoi(number)));
				printf("%s\n");
				ft_memset(number, 0, 11);
				j = 0;
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	simplestring(char *av, t_list *head)
{
	size_t	i;
	size_t	j;
	int		*int_nb;
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
	int_nb = malloc(sizeof(int));
	if (!int_nb)
		return(EXIT_FAILURE);
	*int_nb = ft_atoi(number);
	ft_lstadd_back(&head, ft_lstnew(int_nb));
	printf("%d\n", head->content);
	return (EXIT_SUCCESS);
}

int	argv2lst(t_list *stack_a, int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			if (complexstring(av[i], stack_a) == 1)
				return (EXIT_FAILURE);
		}
		else
		{
			if (simplestring(av[i], stack_a) == 1)
				return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
