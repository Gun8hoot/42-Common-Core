/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:30:16 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/04 04:56:57 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

void	find_elem(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while ((map->grid[i] != NULL))
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'P')
			{
				map->pos_player[0] = j;
				map->pos_player[1] = i;
			}
			else if (map->grid[i][j] == 'E')
			{
				map->pos_escape[0] = j;
				map->pos_escape[1] = i;
			}
			j++;
		}
		i++;
	}
}

bool	check_ext(t_map *map, char *file_path)
{
	char	*ext;

	ext = ft_strchr(file_path, '.');
	if (!ext)
		return (false);
	if (ft_strncmp(ext, ".ber", ft_strlen(ext)))
		return (false);
	map->map_path = file_path;
	return (true);
}

static size_t	countline(t_map *map)
{
	char	*line;
	int		nb_line;
	int		fd;

	fd = 0;
	nb_line = 0;
	fd = open(map->map_path, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (0);
	}
	while (line)
	{
		free(line);
		nb_line++;
		line = get_next_line(fd);
	}
	get_next_line(-1);
	close(fd);
	map->map_size_y = nb_line;
	return (nb_line);
}

bool	init_map(t_map *maps)
{
	int	fd;
	int	y;

	y = 0;
	fd = open(maps->map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	maps->grid = ft_calloc(countline(maps) + 1, sizeof(char *));
	if (!maps->grid)
		return (false);
	maps->grid[y] = get_next_line(fd);
	if (!maps->grid[0])
	{
		close(fd);
		return (false);
	}
	while (maps->grid[y])
	{
		y++;
		maps->grid[y] = get_next_line(fd);
	}
	maps->grid[y] = get_next_line(-1);
	maps->map_size_x = ft_strlen(maps->grid[0]);
	close(fd);
	return (true);
}
