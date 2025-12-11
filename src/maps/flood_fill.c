/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 02:10:17 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/11 15:23:28 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

bool	init_flood_fill(t_map *map)
{
	int		fd;
	int		col;

	col = 0;
	fd = open(map->map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	if (!dup_grid(map, map->grid))
		return (false);
	find_elem(map);
	flood_fill(map, map->pos_player[0], map->pos_player[1], &col);
	close(fd);
	if (map->flood_filled[map->pos_escape[1]][map->pos_escape[0]] != 'F'
		|| col != map->collectible)
		return (safety_free_grid(NULL, map->flood_filled), false);
	close(fd);
	safety_free_grid(NULL, map->flood_filled);
	return (true);
}

void	flood_fill(t_map *map, int pos_x, int pos_y, int *col)
{
	if (pos_x < 0 || pos_x > (map->map_size_x - 1) || pos_y < 0
		|| pos_y > (map->map_size_y - 1)
		|| map->flood_filled[pos_y][pos_x] == '1'
		|| map->flood_filled[pos_y][pos_x] == 'F')
		return ;
	if (map->flood_filled[pos_y][pos_x] == 'C')
		(*col)++;
	map->flood_filled[pos_y][pos_x] = 'F';
	flood_fill(map, pos_x + 1, pos_y, col);
	flood_fill(map, pos_x - 1, pos_y, col);
	flood_fill(map, pos_x, pos_y + 1, col);
	flood_fill(map, pos_x, pos_y - 1, col);
}
