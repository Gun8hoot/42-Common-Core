/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:17:19 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/18 17:50:56 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"
#include <stdbool.h>
#include <stdio.h>

bool	maps_squared(t_map *map)
{
	int		i;
	size_t	len;

	i = 0;
	printf("%d\n", map->map_size_y);
	// while (map->grid[i] != NULL)
	// {
	// 	i++;
	// }
	printf("Good\n");
	return (true);
}

bool	countelem(t_map map)
{
	int	i;

	i = 0;
	
}

bool	maps_walls(t_map *map)
{
	return (true);
}

bool	maps_isvalid(t_map *map, char *map_path)
{
	maps2arr(map, map_path);
	if (maps_squared(map) == false)
		return (false);
	else if (map->collectible < 1)
		return (false);
	else if (map->player != 1)
		return (false);
	else if (map->escape != 1)
		return (false);
	return (true);
}
