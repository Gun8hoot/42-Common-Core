/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:14:48 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/02 17:26:18 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

//	Axis 0 = y || Axis 1 = x

bool	special_event(t_game *game, t_map map, int input, char axis)
{
	if (game->map.grid[game->map.pos_player[0]][game->map.pos_player[1]] == 'C')
	{
		game->map.collectible++;
		game->map.grid[game->map.pos_player[0]][game->map.pos_player[1]] = '0';
	}
	if (input)
	{
		if (axis == 'x')
		{
			game->map.grid[game->map.pos_player[1]][game->map.pos_player[1]+input];

		}
		else
		{
			
		}
	}
}
