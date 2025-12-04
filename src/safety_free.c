/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 10:45:31 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/04 02:58:26 by nclavel          ###   ########.fr       */
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

int	safety_close(t_game *game)
{
	mlx_loop_end(game->mlx_ptr);
	safety_exit_all(game);
	exit(1);
	return (0);
}

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

int	safety_exit_all(t_game *game)
{
	safety_free_grid(game->map.grid, NULL);
	safety_kill_render(game->mlx_ptr, game->win_ptr, game->loop);
	game->mlx_ptr = NULL;
	return (EXIT_SUCCESS);
}
