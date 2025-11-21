#include "test.h"

t_stack	*multiple_argv(char *argv, t_stack **head)
{
	size_t	j;
	t_stack	*node;
	int		minus;
	int		nb;

	j = 0;
	minus = 0;
	node = NULL;
	while (argv[j])
	{
		if (argv[j] == '-')
				minus++;
		if (ft_isdigit(argv[j]) == 0 && minus > 1)
			return (printf("Error\n"), NULL);
		j++;
	}
	nb = atoi(argv);
	printf("%d\n", nb);
	// node = ft_lstnew(&nb);
	// if (!node)
	// 	return (NULL);
	// ft_lstaddback(&head, node);
	return (node);
}

int main(int argc, char **argv)
{
	int i = 1;
	t_stack *head;

	if (argc < 2)
		return(printf("[!] Arguments\n"));
	while(i < argc)
	{
		if (multiple_argv(argv[i], &head) == NULL)
			return(1);
		i++;
	}
	// while (head != NULL)
	// {
	// 	printf("%d\n", head->content);
	// 	head = head->next;
	// }
}
