/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 22:23:13 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/25 14:43:27 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

void	stack_ss(t_stack **head_a, t_stack **head_b)
{
	stack_swap(head_a);
	stack_swap(head_b);
	write(1, "ss\n", 3);
}

void	stack_rr(t_stack **head_a, t_stack **head_b)
{
	stack_rotate(head_a);
	stack_rotate(head_b);
	write(1, "rr\n", 3);
}

void	stack_rrr(t_stack **head_a, t_stack **head_b)
{
	stack_reverse_rotate(head_a);
	stack_reverse_rotate(head_b);
	write(1, "rrr\n", 3);
}