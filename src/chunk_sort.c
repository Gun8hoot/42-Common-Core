/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:56:27 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/25 17:09:08 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

t_stack	init_chunk_sort(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	while (stack_a != NULL)
	{
		stack_push(&stack_a, &stack_b);
		*stack_a = (*stack_a)->next;
	}
	stack_b->next = NULL;
	
}

int	chunk_sort(t_stack *stack_a)
{
	
}