/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 07:55:47 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/28 10:39:13 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b)
{
	size_t	chunk_size;
	size_t	i;
	size_t	size;

	size = stack_list(*stack_a);
	if (size <= 100)
		chunk_size = 20;
	else
		chunk_size = 30;
	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->pos <= i)
		{
			stack_push(stack_a, stack_b, 'b');
			stack_rotate(stack_b, 'b');
			i++;
		}
		else if ((*stack_a)->pos <= i + chunk_size)
		{
			stack_push(stack_a, stack_b, 'b');
			i++;
		}
		else
			stack_rotate(stack_a, 'a');
	}
}

void	push_back_to_a(t_stack **stack_a, t_stack **stack_b)
{
	size_t	max_pos;
	size_t	pos_index;
	size_t	size;

	while (*stack_b)
	{
		max_pos = find_max(*stack_b);
		pos_index = find_pos(*stack_b, max_pos);
		size = stack_list(*stack_b);
		if (pos_index <= size / 2)
		{
			while ((*stack_b)->pos != max_pos)
				stack_rotate(stack_b, 'b');
		}
		else
		{
			while ((*stack_b)->pos != max_pos)
				stack_reverse_rotate(stack_b, 'b');
		}
		stack_push(stack_b, stack_a, 'a');
	}
}
