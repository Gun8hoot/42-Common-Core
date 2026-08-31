/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:56:27 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/28 10:34:54 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	is_sorted(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b)
		return (0);
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

int	init_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (is_sorted(*stack_a, stack_b))
		return (clear_stack(*stack_a, stack_b), EXIT_SUCCESS);
	if (stack_list(*stack_a) <= 3)
		sort_three_nb(stack_a);
	else if (stack_list(*stack_a) == 4 || stack_list(*stack_a) == 5)
		mid_sort(stack_a, &stack_b);
	else if (stack_list(*stack_a) > 5)
	{
		push_chunks_to_b(stack_a, &stack_b);
		push_back_to_a(stack_a, &stack_b);
	}
	clear_stack(*stack_a, stack_b);
	return (EXIT_SUCCESS);
}
