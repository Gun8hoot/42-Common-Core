/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:40:33 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/26 11:44:03 by nclavel          ###   ########.fr       */
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
void	*init_turk_sort(t_stack **stack_a, t_stack **stack_b, t_info **info);
int		*check_all_n_convert(char **tab);
int		algorithm(t_stack **stack_a);
#endif