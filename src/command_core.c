/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:33:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/26 10:22:15 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	stack_swap(t_stack **head)
{
	t_stack	*save_addr_first;
	t_stack	*save_addr_third;
 
	if (!head || !(*head)->next)
		return ;
	save_addr_first = *head;
	save_addr_third = (*head)->next->next;
	*head = (*head)->next;
	(*head)->next = save_addr_first;
	(*head)->next->next = save_addr_third;
}

void	stack_push(t_stack **head_src, t_stack **head_dst)
{
	t_stack	*save;

	if (!head_src || !*head_src)
		return ;
	save = *head_src;
	*head_src = (*head_src)->next;
	save->next = *head_dst;
	*head_dst = save;
}

void	stack_rotate(t_stack **head)
{
	t_stack	*save;
	t_stack *tmp;

	if (!head)
		return ;
	save = *head;
	*head = (*head)->next;
	tmp = stack_list_last(*head);
	tmp->next = save;
	tmp = tmp->next;
	tmp->next = NULL;
}

void	stack_reverse_rotate(t_stack **head)
{
	t_stack	*trunc;
	t_stack	*last_node;

	trunc = NULL;
	if (!head)
		return ;
	trunc = *head;
	while (trunc->next->next != NULL)
		trunc = trunc->next;
	last_node = trunc->next;
	trunc->next = NULL;
	last_node->next = *head;
	*head = last_node;
}