/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:11:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/02 17:08:00 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

int	keypress_action(int key, t_game *game)
{
	if (key == ESC)
		mlx_loop_end(game->mlx_ptr);
	if (key == KEY_W || key == KEY_UP)
	{
				
		ft_printf("\rMove : %d\n", ++game->map.counter);
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{

		ft_printf("\rMove : %d\n", ++game->map.counter);
	}
	if (key == KEY_S || key == KEY_DOWN)
	{

		ft_printf("\rMove : %d\n", ++game->map.counter);
	}
	if (key == KEY_A || key == KEY_LEFT)
	{

		ft_printf("\rMove : %d\n", ++game->map.counter);
	}
	return (0);
}
