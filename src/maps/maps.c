/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:30:16 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/02 12:38:34 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

int	init_flood_fill(t_map *map)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(map->map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	if (!dup_grid(map, map->grid))
		return (false);
	find_elem(map);
	flood_fill(map, map->pos_player[0], map->pos_player[1]);
	close(fd);
	if (map->flood_filled[map->pos_escape[1]][map->pos_escape[0]] != 'F')
		return (safety_free_grid(NULL, map->flood_filled), false);
	close(fd);
	safety_free_grid(NULL, map->flood_filled);
	return (true);
}

void	flood_fill(t_map *map, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x > (map->map_size_x - 1) || pos_y < 0
		|| pos_y > (map->map_size_y - 1)
		|| map->flood_filled[pos_y][pos_x] == '1'
		|| map->flood_filled[pos_y][pos_x] == 'F')
		return ;
	map->flood_filled[pos_y][pos_x] = 'F';
	flood_fill(map, pos_x + 1, pos_y);
	flood_fill(map, pos_x - 1, pos_y);
	flood_fill(map, pos_x, pos_y + 1);
	flood_fill(map, pos_x, pos_y - 1);
}

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
	while ((line = get_next_line(fd)))
	{
		nb_line++;
		free(line);
	}
	close (fd);
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
	while ((maps->grid[y] = get_next_line(fd)))
		y++;
	maps->map_size_x = ft_strlen(maps->grid[0]);
	close(fd);
	return (true);
}
