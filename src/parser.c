/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 13:41:13 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/22 19:23:56 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

t_stack	*created_stack(int	*tab)
{
	t_stack	*stack;
	t_stack	*node;
	int		i;

	i = 0;
	stack = NULL;
	while (tab[i])
	{
		node = stack_new_node(tab[i]);
		stack_add_back(&stack, node);
		i++;
	}
	return (stack);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while(tab[i])
		free(tab[i++]);
}

t_stack	*parser(int argc, char **argv)
{
	char	**arr;
	int		*tab;
	t_stack *stack;

	if (argc == 2)
	{
		arr = ft_split(argv[1], ' ');
		if (!arr)
			return (NULL);
	}
	else
		arr = &argv[1];
	tab = check_all_n_convert(arr);
	if (tab == NULL)
		return (free_tab(arr), NULL);
	stack = created_stack(tab);
	free(tab);
	free_tab(arr);
	if (!stack)
		return (NULL);
	return (stack);
}
