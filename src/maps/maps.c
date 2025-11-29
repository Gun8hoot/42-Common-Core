/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:30:16 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/29 14:12:35 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/so_long.h"

void	flood_fill(t_map *map, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x > (map->map_size_x - 1) || pos_y < 0
		|| pos_y > (map->map_size_y - 1) || map->flood_filled[pos_y][pos_x] == '1' || map->flood_filled[pos_y][pos_x] == 'F')
			return ;
	map->flood_filled[pos_y][pos_x] = 'F';
	flood_fill(map, pos_x + 1, pos_y);
	flood_fill(map, pos_x - 1, pos_y);
	flood_fill(map, pos_x, pos_y + 1);
	flood_fill(map, pos_x, pos_y - 1);
}

void	get_pos(t_map *map)
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

int	init_flood_fill(t_map *map)
{
	size_t	i;
	int		fd;

	i = 0;
	fd = open(map->map_path, O_RDONLY);
	if (fd < 0)
		return (false);

	map->flood_filled = ft_calloc(map->map_size_y + 1, sizeof(char *));
	while ((map->flood_filled[i] = get_next_line(fd)))
		i++;

	get_pos(map);
	flood_fill(map, map->pos_player[0], map->pos_player[1]);
	close(fd);
	if (map->flood_filled[map->pos_escape[0]][map->pos_escape[1]] != 'F')
		return (false);

	return (true);
}

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
	close(fd);
	return (free(line), lb);
}

bool	check_ext(char *file_path)
{
	int	len;

	len = ft_strlen(file_path);
	while(file_path[len] != '.' || len == 0)
	{
		len--;
	}
	if (strncmp(&file_path[len], ".ber", 4))
		return (false);
	return (true);
}

bool	maps2arr(t_map *maps, char *map_path)
{
	int		pos_y;
	int		fd;

	pos_y = 0;
	if (!check_ext(map_path))
		return (false);
	maps->map_path = map_path;
	fd = open(maps->map_path, O_RDONLY);
	if (fd < 0)
		return (false);
	maps->grid = ft_calloc(countline(maps) + 1, sizeof(char *));
	if (!maps->grid)
		return (false);
	while ((maps->grid[pos_y] = get_next_line(fd)))
		pos_y++;
	maps->map_size_x = ft_strlen(maps->grid[0]);
	maps->map_size_y = pos_y;
	close(fd);
	return (true);
}
