/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:02:54 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/11 14:05:32 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

void	display_sprite(t_game *game, int x, int y)
{
	if (!game->mlx_ptr || !game->win_ptr || !game->image.pict.ptr)
		return ;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image.pict.ptr,
		x * WIDTH, y * HEIGHT);
}

static void	player_sprite(t_game *game, t_load_image *images)
{
	if (game->looking_on == 0)
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/player.xpm", &images->pict.width,
				&images->pict.height);
	else if (game->looking_on == 'd')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/player_d.xpm", &images->pict.width,
				&images->pict.height);
	else if (game->looking_on == 'r')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/player_l.xpm", &images->pict.width,
				&images->pict.height);
	else if (game->looking_on == 'l')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player_r.xpm", &images->pict.width,
			&images->pict.height);
	else if (game->looking_on == 't')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player_t.xpm", &images->pict.width,
			&images->pict.height);
}

bool	load_sprite(t_game *game, int x, int y, char c)
{
	t_load_image	*images;

	images = &game->image;
	if (c == 'P')
		player_sprite(game, images);
	else if (c == 'E' && game->map.show_escape)
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/exit.xpm", &images->pict.width, &images->pict.height);
	else if (c == 'C')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/collectible.xpm", &images->pict.width,
				&images->pict.height);
	else if (c == '1')
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/wall.xpm", &images->pict.width, &images->pict.height);
	else if (c == '0' || (c == 'E' && !game->map.show_escape))
		images->pict.ptr = mlx_xpm_file_to_image(game->mlx_ptr,
				"textures/floor.xpm", &images->pict.width,
				&images->pict.height);
	if (images->pict.ptr == NULL)
		return (false);
	display_sprite(game, x, y);
	return (true);
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
			if (!load_sprite(game, x, y, game->map.grid[y][x]))
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
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (false);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.map_size_x * 64,
			game->map.map_size_y * 64, "So_long");
	if (!game->win_ptr)
		return (false);
	ft_memset(&game->image, 0, sizeof(t_load_image));
	gen_frame(game);
	return (true);
}
