/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:29:28 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/25 15:07:16 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H
# include "lib/push_swap.h"
# include <sys/types.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	size_t			pos;
	int				value;
}					t_stack;

// MANAGEMENTS
t_stack				*stack_new_node(int nb);
t_stack				*stack_list_last(t_stack *head);
t_stack				*stack_add_back(t_stack **head, t_stack *node);
void				clear_stack(t_stack *head_a, t_stack *head_b);

// MOVEMENTS
void				stack_swap(t_stack **head);
void				stack_push(t_stack **head_src, t_stack **head_dst);
void				stack_rotate(t_stack **head);
void				stack_reverse_rotate(t_stack **head);
void				stack_ss(t_stack **head_a, t_stack **head_b);
void				stack_rr(t_stack **head_a, t_stack **head_b);
void				stack_rrr(t_stack **head_a, t_stack **head_b);

#endif