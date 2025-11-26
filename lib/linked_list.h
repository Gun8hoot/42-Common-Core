/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:29:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/26 11:08:43 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H
# include "lib/push_swap.h"
# include <sys/types.h>

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	size_t			size;
	int				value;
}					t_stack;

typedef struct	s_info
{
	size_t	size_a;
	size_t	size_b;

}	t_info;

// MANAGEMENTS
size_t				stack_list(t_stack *stack);
t_stack				*stack_list_last(t_stack *head);
t_stack				*stack_new_node(t_stack *stack, int nb);
t_stack				*stack_add_back(t_stack **head, t_stack *node);
void				clear_stack(t_stack *head_a, t_stack *head_b, t_info *info);
void				display_stack(t_stack *stack);

// MOVEMENTS
void				stack_swap(t_stack **head);
void				stack_rotate(t_stack **head);
void				stack_reverse_rotate(t_stack **head);
void				stack_ss(t_stack **head_a, t_stack **head_b);
void				stack_rr(t_stack **head_a, t_stack **head_b);
void				stack_rrr(t_stack **head_a, t_stack **head_b);
void				stack_push(t_stack **head_src, t_stack **head_dst);

#endif