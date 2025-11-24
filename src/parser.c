/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:41:13 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/24 16:47:02 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

t_stack	*created_stack(int *tab, size_t len)
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
		while (arr[j])
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

char	**argv2arr(int argc, char **argv)
{
	char	**arr;
	size_t	i;
	size_t	nb_char;

	i = 0;
	arr = ft_calloc(argc, sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < (argc - 1))
	{
		nb_char = 0;
		arr[i] = ft_calloc(ft_strlen(argv[i + 1]) + 1, sizeof(char));
		if (arr[i] == NULL)
			return (ft_free_alem(arr, i), NULL);
		ft_strcpy(arr[i], argv[i + 1]);
		i++;
	}
	i = 0;
	while (arr[i] != NULL)
		i++;
	return (arr);
}

t_stack	*parser(int argc, char **argv)
{
	char	**arr;
	t_stack	*stack;
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
