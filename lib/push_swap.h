/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:40:33 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/22 19:13:59 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "external/libft/libft.h"
# include "external/printf/lib/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>

typedef struct s_stack
{
	struct s_stack	*next;
	size_t			pos;
	int				value;
} t_stack;

t_stack	*parser(int argc, char **argv);
int	*check_all_n_convert(char **tab);
t_stack	*stack_add_back(t_stack **head, t_stack *node);
t_stack	*stack_list_last(t_stack *head);
t_stack	*stack_new_node(int nb);
t_stack	*three_in_one(t_stack **head, char *number);

#endif