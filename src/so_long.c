/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:54:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/04 02:42:27 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

int	temp(t_game *game)
{
	mlx_loop_end(game->mlx_ptr);
	safety_exit_all(game);
	exit(1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		return (printf("Missing arguments\n"), EXIT_FAILURE);
	if (!maps_isvalid(&game.map, argv[1]))
	{
		ft_putstr_fd("Error\n", 2);
		return (safety_free_grid(game.map.grid, NULL), EXIT_FAILURE);
	}
	if (!render(&game))
	{
		ft_putstr_fd("Error\n", 2);
		return (safety_free_grid(game.map.grid, NULL), EXIT_FAILURE);
	}
	mlx_hook(game.win_ptr, ON_DESTROY, 0, &temp, &game.mlx_ptr);
	mlx_key_hook(game.win_ptr, &keypress_action, &game);
	game.loop = true;
	mlx_loop(game.mlx_ptr);
	if (game.mlx_ptr)
		safety_exit_all(&game);
	return (EXIT_SUCCESS);
}
