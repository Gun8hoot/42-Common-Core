/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:02:54 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/01 14:35:25 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

void	sprite4map(t_game *game)
{
	(void)game;
		
}

void	move_in_map(t_game *game)
{
	(void)game;
	// while(game->map[])
}

bool	render(t_game *game)
{
	printf("%p\n", game->win_ptr);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.map_size_x * 64, game->map.map_size_y * 64, "Sooooo_longggg");
	if (!game->win_ptr)
		return (false);
	ft_memset(&game->image, 0, sizeof(t_img));
	mlx_loop(game->mlx_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	return (true);
}