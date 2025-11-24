/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:33:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/24 17:38:09 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	stack_sa(t_stack *head_a)
{
	t_stack	*save_addr_first;
	t_stack	*save_addr_second;
	t_stack	*save_addr_third;
 
	save_addr_first = head_a;
	save_addr_second = head_a->next;
	save_addr_third = head_a->next->next;
	save_addr_second->next = save_addr_first;
	save_addr_second->next->next = save_addr_third;
	head_a = save_addr_second;
}

void	stack_sb(t_stack *head_b)
{
	int	save;

	save = head_b->next->value;
	head_b->next->value = head_b->value;
	head_b->value = save;
}

void	stack_pa(t_stack **head_a, t_stack *head_b)
{
	t_stack	*save;

	save = head_b;
	save->next = *head_a;
}

void	stack_pb(t_stack **head_b, t_stack *head_a)
{
	t_stack	*save;

	save = head_a;
	save->next = *head_b;
}
