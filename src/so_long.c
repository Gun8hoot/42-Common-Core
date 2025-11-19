/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:54:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/18 17:49:09 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int i = 0;

	if (argc != 2)
	{
		printf("Missing arguments\n");
		return (EXIT_FAILURE);
	}
	if (maps_isvalid(&map, argv[1]) == false)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	// printf("%s", map.grid[0]);
}