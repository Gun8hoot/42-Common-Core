/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:02:54 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/29 17:05:39 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

bool	render(t_game *game)
{
	int	height;
	int	width;

	height = 64;
	width = 64;
	game->mlx_ptr = mlx_init();
	mlx_new_window(game->mlx_ptr, game->map.map_size_x * 64, game->map.map_size_y * 64, "Sooooo_longggg");
	mlx_xpm_file_to_image(game->mlx_ptr, "textures/player.xpm", &height, &width);
	mlx_loop(game->mlx_ptr);
	return (true);
}