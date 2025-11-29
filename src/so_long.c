/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:54:20 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/29 14:44:17 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;

	ft_memset(&map, 0, sizeof(t_map));
	if (argc != 2)
		return (printf("Missing arguments\n"), EXIT_FAILURE);
	if (maps_isvalid(&map, argv[1]) == false)
	{
		printf("Error\n");
		return (safety_free_grid(map), EXIT_FAILURE);
	}
	safety_free_grid(map);
}
