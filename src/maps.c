/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:30:16 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/18 17:25:28 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

size_t	countline(t_map *map)
{
	int		bytes;
	char	*line;
	int		fd;
	int		i;
	int		lb;

	i = 0;
	lb = 1;
	bytes = 1;
	fd = open(map->map_path, O_RDONLY);
	line = malloc(41);
	while (bytes > 0)
	{
		i = 0;
		bytes = read(fd, line, 40);
		line[bytes] = '\0';
		while (line[i])
		{
			if (line[i] == '\n')
				lb++;
			i++;
		}
	}
	free(line);
	return (lb);
}

bool	maps2arr(t_map *maps, char *map_path)
{
	int		pos_y;
	int		fd;

	pos_y = 0;
	maps->map_path = map_path;
	maps->grid = malloc(sizeof(char *) * countline(maps));
	if (!maps->grid)
		return (false);
	fd = open(maps->map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	while ((maps->grid[pos_y] = get_next_line(fd)))
		pos_y++;
	maps->map_size_x = ft_strlen(maps->grid[0]);
	maps->map_size_y = pos_y;
	return (true);
}
