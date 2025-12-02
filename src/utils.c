/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:20:33 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/02 12:11:56 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

bool	dup_grid(t_map *map, char **grid)
{
	int i;

	i = 0;
	map->flood_filled = ft_calloc(map->map_size_y + 1, sizeof(char *));
	if (!map->flood_filled)
		return (false);
	while (grid[i])
	{
		map->flood_filled[i] = ft_strdup(grid[i]);
		if (!map->flood_filled[i])
		{
			safety_free_grid(map->grid, map->flood_filled);
			return (false);
		}
		// printf("%s\n", map->flood_filled[i]);
		i++;
	}
	map->flood_filled[i] = NULL;
	return (true);
}