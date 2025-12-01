/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:11:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/01 14:12:33 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

int		keypress_action(int key, t_game *game)
{
	if (key == ESC)
		mlx_loop_end(game->mlx_ptr);
	if (key == KEY_W)
		;
	if (key == KEY_D)
		;
	if (key == KEY_S)
		;
	if (key == KEY_A)
		;
	return (0);
}