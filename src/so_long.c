/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:54:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/01 17:46:33 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game.map, 0, sizeof(t_map));
	if (argc != 2)
		return (printf("Missing arguments\n"), EXIT_FAILURE);
	if (maps_isvalid(&game.map, argv[1]) == false)
	{
		ft_putstr_fd("Error parsing\n", 2);
		return (safety_free_grid(game.map), EXIT_FAILURE);
	}
	if (!render(&game))
		return(safety_free_grid(game.map), ft_putstr_fd("Error\n", 2), 0);
	mlx_hook(game.win_ptr, ON_DESTROY, 0, &safety_exit_all, &game);
	mlx_key_hook(game.win_ptr, &keypress_action, &game);
	mlx_loop(game.mlx_ptr);
	safety_exit_all(game);
	return(EXIT_SUCCESS);
}
