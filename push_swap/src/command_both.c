/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:23:13 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/27 08:43:22 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int	stack_ss(t_stack **head_a, t_stack **head_b)
{
	if (!head_a || !head_b)
		return (0);
	stack_swap(head_a, 'x');
	stack_swap(head_b, 'x');
	write(1, "ss\n", 3);
	return (1);
}

int	stack_rr(t_stack **head_a, t_stack **head_b)
{
	if (!head_a || !*head_a || !head_b || !*head_b)
		return (0);
	stack_rotate(head_a, 'x');
	stack_rotate(head_b, 'x');
	write(1, "rr\n", 3);
	return (1);
}

int	stack_rrr(t_stack **head_a, t_stack **head_b)
{
	if (!head_a || !head_b)
		return (0);
	stack_reverse_rotate(head_a, 'x');
	stack_reverse_rotate(head_b, 'x');
	write(1, "rrr\n", 3);
	return (1);
}