/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:54:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/01 14:34:50 by nclavel          ###   ########.fr       */
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
	if (!(game.mlx_ptr = mlx_init()))
		return (ft_putstr_fd("Error MLX\n", 2), EXIT_FAILURE);
	if (!render(&game))
		return(ft_putstr_fd("Error render\n", 2), EXIT_FAILURE);
	safety_free_grid(game.map);
	return(EXIT_SUCCESS);
}
