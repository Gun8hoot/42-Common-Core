/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:02:54 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/01 17:46:31 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

bool	load_sprite(t_game *game, t_load_image *images, int x, int y, char c)
{
	if (c == 'P')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "textures/player.xpm", &images->pict.width, &images->pict.height);
	else if (c == 'E')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "texture/exit.xpm", &images->pict.width, &images->pict.height);
	else if (c == 'C')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "texture/collectible.xpm", &images->pict.width, &images->pict.height);
	else if (c == '1')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "texture/wall.xpm", &images->pict.width, &images->pict.height);
	else if (c == '0')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr, "texture/floor.xpm", &images->pict.width, &images->pict.height);
	// printf("[DEB] img ptr : %p : %c", images->pict.ptr, c);
	if (images->pict.ptr == NULL)
		return (false);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, images->pict.ptr, x * WIDTH, y * HEIGHT);
	return (true);
}

bool	gen_frame(t_game *game)
{
	int *x;
	int *y;

	x = &game->map.pos_x;
	y = &game->map.pos_y;
	while (game->map.grid[*y])
	{
		while (game->map.grid[*y][*x])
		{
			if (!load_sprite(game, &game->image, *x, *y,  game->map.grid[*y][*x]))
				return (false);
			x++;
		}
		y++;
	}
	return (true);
}

bool	render(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (false);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.map_size_x * 64,
		game->map.map_size_y * 64, "Sooooo_longggg");
	if (!game->win_ptr)
		return (false);
	ft_memset(&game->image, 0, sizeof(t_load_image));

	gen_frame(game);
	return (true);
}
