/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:33:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/22 22:22:28 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	stack_sa(t_stack *head_a)
{
	int	save;

	save = head_a->next->value;
	head_a->next->value = head_a->value;
	head_a->value = save;
}

void	stack_sb(t_stack *head_b)
{
	int	save;

	save = head_b->next->value;
	head_b->next->value = head_b->value;
	head_b->value = save;
}

void	stack_ss(t_stack *head_a, t_stack *head_b)
{
	stack_sa(head_a);
	stack_sb(head_b);
}

void	stack_pa(t_stack **head_a, t_stack *head_b)
{
	t_stack *save;

	save = head_b;
	save->next = head_a;
}

void	stack_pb(t_stack **head_b, t_stack *head_a)
{
	t_stack *save;

	save = head_a;
	save->next = head_b;
}