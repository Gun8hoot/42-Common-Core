/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:33:45 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/22 18:25:33 by nclavel          ###   ########.fr       */
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
