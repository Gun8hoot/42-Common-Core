/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:33:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/25 11:55:02 by nclavel          ###   ########.fr       */
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

	if (!head_src)
		return ;
	save = *head_src;
	*head_src = (*head_src)->next;
	*head_dst = save;
}

void	stack_rotate(t_stack **head)
{
	t_stack	*save;
	t_stack *tmp;

	save = *head;
	*head = (*head)->next;
	tmp = stack_list_last(*head);
	tmp->next = save;
	tmp = tmp->next;
	tmp->next = NULL;
}

void	stack_reverse_rotate(t_stack **head)
{
	t_stack	*save;
	t_stack	*save2;
	t_stack *tmp;

	save2 = *head;
	tmp = stack_list_last(*head);
	save = tmp;
	*head = save;
	save->next = save2;
}