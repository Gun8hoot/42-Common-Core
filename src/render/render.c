/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:02:54 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/02 17:20:23 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

bool	load_sprite(t_game *game, t_load_image *images, int x, int y, char c)
{
	if (c == 'P')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/player.xpm", &images->pict.width,
				&images->pict.height);
	else if (c == 'E')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/exit.xpm", &images->pict.width, &images->pict.height);
	else if (c == 'C')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/collectible.xpm", &images->pict.width,
				&images->pict.height);
	else if (c == '1')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/wall.xpm", &images->pict.width, &images->pict.height);
	else if (c == '0')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/floor.xpm", &images->pict.width, &images->pict.height);
	if (images->pict.ptr == NULL)
		return (false);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images->pict.ptr, x
		* WIDTH, y * HEIGHT);
	return (true);
}

bool	update_frame(t_game game, int input)
{

}

bool	gen_frame(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map.grid[y])
	{
		x = 0;
		while (game->map.grid[y][x])
		{
			if (!load_sprite(game, &game->image, x, y,
					game->map.grid[y][x]))
				return (false);
			mlx_destroy_image(game->mlx_ptr, game->image.pict.ptr);
			game->image.pict.ptr = NULL;
			x++;
		}
		y++;
	}
	return (true);
}

bool	render(t_game *game)
{
	int i = 0;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (false);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.map_size_x * 64,
			game->map.map_size_y * 64, "Sooooo_longggg");
	if (!game->win_ptr)
		return (false);
	while (game->map.grid[i])
	{
		ft_printf("%d : %s\n", i, game->map.grid[i]);
		i++;
	}
	ft_memset(&game->image, 0, sizeof(t_load_image));
	gen_frame(game);
	return (true);
}
