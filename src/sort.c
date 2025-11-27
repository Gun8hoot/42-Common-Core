/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:56:27 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/27 15:24:56 by nclavel          ###   ########.fr       */
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
			while (rotations > 0)
			{
				stack_rotate(stack_a, 'a');
				rotations--;
			}
		}
		else
		{
			rotations = size - min_pos;
			while (rotations > 0)
			{
				stack_reverse_rotate(stack_a, 'a');
				rotations--;
			}
		}
		stack_push(stack_a, stack_b, 'b');
	}
	sort_three_nb(stack_a);
	while (stack_list(*stack_b) > 0)
		stack_push(stack_b, stack_a, 'a');
}

int	init_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	t_info	*info;

	info = malloc(sizeof(t_info));
	if (!info)
		return (EXIT_FAILURE);
	ft_memset(info, 0, sizeof(t_info));
	stack_b = NULL;
	if (is_sorted(*stack_a, stack_b))
		return (clear_stack(*stack_a, stack_b, info), EXIT_SUCCESS);
	if (stack_list(*stack_a) <= 3)
		sort_three_nb(stack_a);
	else if (stack_list(*stack_a) == 4 || stack_list(*stack_a) == 5)
		mid_sort(stack_a, &stack_b);
	// else if (stack_list(*stack_a) > 5)
	// {
	// 	;
	// 	;
	// }
	// find_min(*stack_a);
	display_stack(*stack_a);
	clear_stack(*stack_a, stack_b, info);
	return (EXIT_SUCCESS);
}
