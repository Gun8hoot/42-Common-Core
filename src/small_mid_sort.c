/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_mid_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 08:03:25 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/28 08:09:09 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	sort_three_nb(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!*stack || !(*stack)->next)
		return ;
	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && a < c && b < c)
		stack_swap(stack, 'a');
	else if (a > b && a > c && b < c)
		stack_rotate(stack, 'a');
	else if (a < b && a > c && b > c)
		stack_reverse_rotate(stack, 'a');
	else if (a > b && a > c && b > c)
	{
		stack_swap(stack, 'a');
		stack_reverse_rotate(stack, 'a');
	}
	else if (a < b && a < c && b > c)
		(stack_swap(stack, 'a'), stack_rotate(stack, 'a'));
}

void	mid_sort(t_stack **stack_a, t_stack **stack_b)
{
	size_t	size;
	size_t	min_pos;
	size_t	rotations;

	while (stack_list(*stack_a) > 3)
	{
		min_pos = find_min(*stack_a);
		size = stack_list(*stack_a);
		if (min_pos <= size / 2)
		{
			rotations = min_pos;
			while (rotations-- > 0)
				stack_rotate(stack_a, 'a');
		}
		else
		{
			rotations = size - min_pos;
			while (rotations-- > 0)
				stack_reverse_rotate(stack_a, 'a');
		}
		stack_push(stack_a, stack_b, 'b');
	}
	sort_three_nb(stack_a);
	while (stack_list(*stack_b) > 0)
		stack_push(stack_b, stack_a, 'a');
}
