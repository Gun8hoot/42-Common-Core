/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:11:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/11 14:16:15 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

void	move(t_game *game, t_map *map, int pos_x, int pos_y)
{
	check_event(game, pos_x, pos_y);
	if (map->pos_player[1] == map->pos_escape[1]
		&& map->pos_player[0] == map->pos_escape[0])
		map->grid[map->pos_player[1]][map->pos_player[0]] = 'E';
	else
		map->grid[map->pos_player[1]][map->pos_player[0]] = '0';
	map->grid[pos_y][pos_x] = 'P';
	map->pos_player[1] = pos_y;
	map->pos_player[0] = pos_x;
}

bool	mouvement(t_game *game, int px, int py)
{
	int	pos_x;
	int	pos_y;

	pos_x = game->map.pos_player[0] + px;
	pos_y = game->map.pos_player[1] + py;
	if (game->map.grid[pos_y][pos_x] == '1')
		return (false);
	move(game, &game->map, pos_x, pos_y);
	ft_printf("Move : %d\n", ++game->map.counter);
	gen_frame(game);
	return (true);
}

int	keypress_action(int key, t_game *game)
{
	if (key == ESC)
		mlx_loop_end(game->mlx_ptr);
	if (key == KEY_W || key == KEY_UP)
	{
		game->looking_on = 't';
		mouvement(game, 0, -1);
	}
	if (key == KEY_D || key == KEY_RIGHT)
	{
		game->looking_on = 'l';
		mouvement(game, 1, 0);
	}
	if (key == KEY_S || key == KEY_DOWN)
	{
		game->looking_on = 'd';
		mouvement(game, 0, +1);
	}
	if (key == KEY_A || key == KEY_LEFT)
	{
		game->looking_on = 'r';
		mouvement(game, -1, 0);
	}
	return (0);
}
