/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:01:09 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/26 11:43:24 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

t_stack	*stack_new_node(t_stack *stack, int nb)
{
	t_stack	*node;

	node = NULL;
	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = nb;
	node->next = NULL;
	if (!stack)
		node->prev = NULL;
	else
		node->prev = stack;
	return (node);
}

t_stack	*stack_list_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

t_stack	*stack_add_back(t_stack **head, t_stack *node)
{
	t_stack	*last;

	if (!*head)
	{
		*head = node;
		return (*head);
	}
	last = stack_list_last(*head);
	last->next = node;
	node->prev = last;
	return (*head);
}

size_t	stack_list(t_stack *stack)
{
	size_t	number;

	number = 0;
	while (stack != NULL)
	{
		stack = stack->next;
		number++;
	}
	return (number);
}

void	clear_stack(t_stack *head_a, t_stack *head_b, t_info *info)
{
	t_stack	*hold_addr;

	if (head_a)
	{
		while (head_a->next != NULL)
		{
			hold_addr = head_a->next;
			free(head_a);
			head_a = hold_addr;
		}
		free(head_a);
	}
	if (head_b)
	{
		while (head_b->next != NULL)
		{
			hold_addr = head_b->next;
			free(head_b);
			head_b = hold_addr;
		}
		free(head_b);
	}
	if (info)
		free(info);
}
