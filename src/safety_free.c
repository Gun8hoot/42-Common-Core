/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:45:31 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/27 13:05:39 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

void	safety_free_grid(t_map map)
{
	size_t	pos_y;

	pos_y = 0;
	if (map.grid)
	{
		while (pos_y <= map.map_size_y - 1)
		{
			free(map.grid[pos_y]);
			pos_y++;
		}
		free(map.grid);	
	}
	if (map.flood_filled)
	{
		while (pos_y <= map.map_size_y - 1)
			{
				free(map.grid[pos_y]);
				pos_y++;
			}
			free(map.grid);	
	}
}
