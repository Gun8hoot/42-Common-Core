/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:56:27 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/26 11:46:33 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	algorithm(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (EXIT_FAILURE);
	ft_memset(info, 0, sizeof(t_info));
	stack_b = NULL;
	init_turk_sort(stack_a, &stack_b, &info);

	clear_stack(*stack_a, stack_b, info);
	return (EXIT_SUCCESS);
}

void	*init_turk_sort(t_stack **stack_a, t_stack **stack_b, t_info **info)
{
	size_t	i;

	i = 0;
	(*info)->size_a = stack_list(*stack_a);
	while ((*info)->size_a > 3)
	{
		stack_push(stack_a, stack_b);
		(*info)->size_a -= 1;
		(*info)->size_b += 1;
	}
}

int	turk_sort(t_stack *stack_a)
{
	(void)stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	return (0);
}