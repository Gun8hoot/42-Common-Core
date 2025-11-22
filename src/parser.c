/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:41:13 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/22 22:58:21 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

t_stack	*created_stack(int	*tab, size_t len)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	i = 0;
	stack = NULL;
	while (i < len)
	{
		node = stack_new_node(tab[i]);
		stack_add_back(&stack, node);
		i++;
	}
	return (stack);
}

void	ft_free_alem(char **arr, int j)
{
	if (j == 0)
	{
		while(arr[j])
			j++;
	}
	j -= 1;
	while (j >= 0)
	{
		free(arr[j]);
		j--;
	}
	free(arr);
}

char **argv2arr(int argc, char **argv)
{
	char	**arr;
	size_t	nb_tab;
	size_t	nb_char;

	nb_tab = 0;
	arr = malloc(sizeof(char *) * argc);
	if (!arr)
		return(NULL);
	while ((nb_tab + 1) < argc)
	{
		nb_char = 0;
		arr = malloc(sizeof(char) * (ft_strlen(argv[nb_tab + 1]) + 1));
		if (!arr)
			return(ft_free_alem(arr, nb_tab), NULL);
		while (argv[nb_tab + 1][nb_char])
		{
			arr[nb_tab][nb_char] = argv[nb_tab + 1][nb_char];			// SEGFAULT DE SES MORT ICI
			nb_char++;
		}
		arr[nb_tab][nb_char] = '\0';
		nb_tab++;
	}
	arr[nb_tab] = NULL;
	return (arr);
}

t_stack	*parser(int argc, char **argv)
{
	char	**arr;
	t_stack *stack;
	int		*tab;
	size_t	len;

	len = 0;
	if (argc == 2)
		arr = ft_split(argv[1], ' ');
	else
		arr = argv2arr(argc, argv);
	if (!arr)
			return (NULL);
	tab = check_all_n_convert(arr);
	if (tab == NULL)
		return (ft_free_alem(arr, 0), NULL);
	while (arr[len])
		len++;
	stack = created_stack(tab, len);
	free(tab);
	ft_free_alem(arr, 0);
	if (!stack)
		return (NULL);
	return (stack);
}
