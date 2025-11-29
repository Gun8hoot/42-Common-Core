/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:54:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/29 16:14:52 by nclavel          ###   ########.fr       */
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
		printf("Error\n");
		return (safety_free_grid(game.map), EXIT_FAILURE);
	}
	render(&game);
	safety_free_grid(game.map);
}
