/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:45:31 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/02 11:46:43 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

void	safety_free_grid(char **grid, char **flood_grid)
{
	int	pos_y;

	pos_y = 0;
	if (grid)
	{
		while (grid[pos_y])
		{
			free(grid[pos_y]);
			pos_y++;
		}
		free(grid);
	}
	pos_y = 0;
	if (flood_grid)
	{
		while (flood_grid[pos_y])
		{
			free(flood_grid[pos_y]);
			pos_y++;
		}
		free(flood_grid);
	}
}

// void	free_picture(t_game game, t_load_image images)
// {
// 	if (images.player.ptr)
// 		mlx_destroy_image(game.mlx_ptr, images.player.ptr);
// 	if (images.collectible.ptr)
// 		mlx_destroy_image(game.mlx_ptr, images.collectible.ptr);
// 	if (images.exit.ptr)
// 		mlx_destroy_image(game.mlx_ptr, images.exit.ptr);
// 	if (images.floor.ptr)
// 		mlx_destroy_image(game.mlx_ptr, images.floor.ptr);
// 	if (images.wall.ptr)
// 		mlx_destroy_image(game.mlx_ptr, images.wall.ptr);
// }

void	safety_kill_render(void *mlx_ptr, void *win_ptr, bool loop)
{
	if (win_ptr)
		mlx_destroy_window(mlx_ptr, win_ptr);
	if (mlx_ptr)
	{
		if (loop)
			mlx_loop_end(mlx_ptr);
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
	}
}

int		safety_exit_all(t_game *game)
{
	safety_free_grid(game->map.grid, NULL);
	safety_kill_render(game->mlx_ptr, game->win_ptr, game->loop);
	// free_picture(game, game.image);
	game->mlx_ptr = NULL;
	return (EXIT_SUCCESS);
}