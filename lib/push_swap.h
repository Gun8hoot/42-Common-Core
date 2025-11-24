/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:40:33 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/24 17:38:17 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "external/libft/libft.h"
# include "external/printf/lib/ft_printf.h"
# include <ctype.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*next;
	size_t			pos;
	int				value;
}					t_stack;

typedef struct s_data
{
	size_t			pos;
	size_t			counter;
}					t_data;

t_stack				*parser(int argc, char **argv);
int					*check_all_n_convert(char **tab);
t_stack				*stack_add_back(t_stack **head, t_stack *node);
t_stack				*stack_list_last(t_stack *head);
t_stack				*stack_new_node(int nb);
t_stack				*three_in_one(t_stack **head, char *number);
void				clear_stack(t_stack *head_a, t_stack *head_b);
void				stack_sa(t_stack *head_a);

#endif