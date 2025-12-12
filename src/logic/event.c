/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:14:48 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/12 09:08:04 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

//	Axis 0 = y || Axis 1 = x

void	game_end(t_game *game)
{
	ft_printf("\n\x1b[0;32mCongrat, you finish the game !\x1b[0m\n");
	ft_printf("+-- TOTAL MOVES --+\n");
	ft_printf("\t %d\n", game->map.counter + 1);
	safety_close(game);
}

void	check_event(t_game *game, int pos_x, int pos_y)
{
	t_map	*map;

	map = &game->map;
	if (map->grid[pos_y][pos_x] == 'C')
		map->collec_pick_up++;
	if (map->collectible == map->collec_pick_up)
		map->show_escape = 1;
	if (map->grid[pos_y][pos_x] == 'E' && map->show_escape == 1)
		game_end(game);
}
