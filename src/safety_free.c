/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:45:31 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/01 16:57:56 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

void	safety_free_grid(t_map map)
{
	int	pos_y;

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
	pos_y = 0;
	if (map.flood_filled)
	{
		while (pos_y <= map.map_size_y - 1)
			{
				free(map.flood_filled[pos_y]);
				pos_y++;
			}
			free(map.flood_filled);	
	}
}

void	free_picture(t_game game, t_load_image images)
{
	if (images.player.ptr)
		mlx_destroy_image(game.mlx_ptr, images.player.ptr);
	if (images.collectible.ptr)
		mlx_destroy_image(game.mlx_ptr, images.collectible.ptr);
	if (images.exit.ptr)
		mlx_destroy_image(game.mlx_ptr, images.exit.ptr);
	if (images.floor.ptr)
		mlx_destroy_image(game.mlx_ptr, images.floor.ptr);
	if (images.wall.ptr)
		mlx_destroy_image(game.mlx_ptr, images.wall.ptr);
}

int	safety_exit_all(t_game game)
{
	safety_free_grid(game.map);
	if (game.win_ptr)
		mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	if (game.mlx_ptr)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
	}
	// free_picture(game, game.image);
	return (EXIT_SUCCESS);
}