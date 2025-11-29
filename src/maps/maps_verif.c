/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:17:19 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/29 14:41:19 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"
#include <stdbool.h>
#include <stdio.h>

bool	maps_check_char(t_map *map)
{
	int 	i;
	int 	j;
	char	c;

	i = 0;
	while ((map->grid[i]))
	{
		j = 0;
		while (map->grid[i][j])
		{
			c = map->grid[i][j];
			if (!ft_isdigit(c) && (c != '\n' && c != 'P' && c != 'E' && c != 'C'))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	maps_squared(t_map *map)
{
	int		i;
	size_t	len;
	size_t	tmp_len;

	i = 1;
	tmp_len = 0;
	len = ft_strlen(map->grid[0]);
	if (map->grid[0][len - 1] == '\n')
		len--;
	while (map->grid[i])
	{
		tmp_len = ft_strlen(map->grid[i]);
		if (map->grid[i][tmp_len - 1] == '\n')
			tmp_len--;
		if (tmp_len != len)
			return (false);
		i++;
	}
	map->map_size_x = len;
	return (true);
}

void	countelem(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'C')
				map->collectible++;
			if (map->grid[i][j] == 'E')
				map->escape++;
			if (map->grid[i][j] == 'P')
				map->player++;
			j++;
		}
		i++;
	}
}

bool	maps_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->grid[i])
	{
		j = 0;
		if (i == 0 || i == (map->map_size_y - 1))
		{
			while(map->grid[i][j] && map->grid[i][j] != '\n')
				j++;
			if (map->map_size_x != j)
				return (false);
		}
		else
		{
			if (map->grid[i][0] != '1' || map->grid[i][map->map_size_x - 1] != '1')
				return (false);
		}
		i++;
	}
	return (true);
}

bool	maps_isvalid(t_map *map, char *map_path)
{
	if (!maps2arr(map, map_path))
		return (false);
	if (maps_squared(map) != true)
		return (false);
	if (maps_check_char(map) != true)
		return (false);
	countelem(map);
	if (map->collectible < 1)
		return (false);
	else if (map->player != 1)
		return (false);
	else if (map->escape != 1)
		return (false);
	else if (maps_walls(map) != true)
		return (false);
	// else if (init_flood_fill(map) != true)
		// return (false);
	printf("map correct\n");
	return (true);
}
