/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:33:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/28 09:19:25 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	stack_swap(t_stack **head, char c)
{
	t_stack	*save_addr_first;
	t_stack	*save_addr_third;

	save_addr_third = NULL;
	if (!head || !(*head)->next)
		return (0);
	save_addr_first = *head;
	if ((*head)->next->next)
		save_addr_third = (*head)->next->next;
	*head = (*head)->next;
	(*head)->next = save_addr_first;
	if (save_addr_third)
		(*head)->next->next = save_addr_third;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	return (1);
}

int	stack_push(t_stack **head_src, t_stack **head_dst, char c)
{
	t_stack	*save;

	if (!head_src || !*head_src)
		return (0);
	save = *head_src;
	*head_src = (*head_src)->next;
	save->next = *head_dst;
	if (!head_dst)
		save->prev = NULL;
	*head_dst = save;
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
	return (1);
}

int	stack_rotate(t_stack **head, char c)
{
	t_stack	*save;
	t_stack	*tmp;

	if (!head || !*head || !(*head)->next)
		return (0);
	save = *head;
	*head = (*head)->next;
	tmp = stack_list_last(*head);
	tmp->next = save;
	tmp = tmp->next;
	tmp->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	return (1);
}

int	stack_reverse_rotate(t_stack **head, char c)
{
	t_stack	*trunc;
	t_stack	*last_node;

	trunc = NULL;
	if (!head)
		return (0);
	trunc = *head;
	while (trunc->next->next != NULL)
		trunc = trunc->next;
	last_node = trunc->next;
	trunc->next = NULL;
	last_node->next = *head;
	*head = last_node;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	return (1);
}
