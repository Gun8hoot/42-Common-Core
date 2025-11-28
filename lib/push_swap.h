/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:40:33 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/28 08:17:03 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "external/libft/libft.h"
# include "external/printf/lib/ft_printf.h"
# include "lib/linked_list.h"
# include <ctype.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

t_stack	*parser(int argc, char **argv);
size_t	find_max(t_stack *stack);
size_t	find_min(t_stack *stack);
size_t	find_pos(t_stack *stack, size_t index);
int		*check_all_n_convert(char **tab);
int		init_sort(t_stack **stack_a);
void	mid_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_three_nb(t_stack **stack);
void	push_chunks_to_b(t_stack **stack_a, t_stack **stack_b);
void	push_back_to_a(t_stack **stack_a, t_stack **stack_b);

#endif