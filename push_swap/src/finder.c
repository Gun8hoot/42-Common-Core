/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 10:01:37 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/27 15:16:07 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

size_t	find_max(t_stack *stack)
{
	size_t	index_max;

	if (!stack)
		return (-1);
	index_max = stack->pos;
	while (stack)
	{
		if (stack->pos > index_max)
		{
			index_max = stack->pos;
		}
		stack = stack->next;
	}
	return (index_max);
}

size_t	find_pos(t_stack *stack, size_t index)
{
	size_t	pos;

	pos = 0;
	while (stack)
	{
		if (stack->pos == index)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (-1);
}

size_t	find_min(t_stack *stack)
{
	size_t	index;
	size_t	min_index;
	size_t	min_value;
	t_stack	*temp;

	if (!stack)
		return (-1);
	index = 0;
	min_index = 0;
	temp = stack;
	min_value = temp->pos;
	while (temp)
	{
		if (temp->pos < min_value)
		{
			min_value = temp->pos;
			min_index = index;
		}
		temp = temp->next;
		index++;
	}
	return (min_index);
}