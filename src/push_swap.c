/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 17:33:51 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/26 11:28:44 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/push_swap.h"

int main(int argc, char **argv)
{
	t_stack *stack_a;

	if (argc < 2)
		return (1);
	stack_a = parser(argc, argv);
	if (argv[1][0] == '\0' || !stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!algorithm(&stack_a))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
