/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:54:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/28 15:49:30 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int i = 0;

	ft_memset(&map, 0, sizeof(t_map));
	if (argc != 2)
	{
		printf("Missing arguments\n");
		return (EXIT_FAILURE);
	}
	if (maps_isvalid(&map, argv[1]) == false)
	{
		printf("Error\n");
		safety_free_grid(map);
		return (EXIT_FAILURE);
	}
	safety_free_grid(map);
	// printf("%s", map.grid[0]);
}