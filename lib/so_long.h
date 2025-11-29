/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:02:24 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/29 14:42:35 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "external/gnl/get_next_line.h"
# include "external/libft/libft.h"
# include "external/minilibx-linux/mlx.h"
# include "external/minilibx-linux/mlx_int.h"
# include "external/printf/lib/ft_printf.h"
# include "external/minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**flood_filled;
	int		pos_player[2];
	int		pos_escape[2];
	int		collectible;
	int		map_size_x;
	int		map_size_y;
	char	*map_path;
	char	**grid;
	int		player;
	int		escape;
}			t_map;

typedef struct s_game
{
	void	*x;
	void	*y;
	t_map	map;
}			t_game;

bool		maps2arr(t_map *maps, char *map_path);
bool		maps_isvalid(t_map *map, char *map_path);
void		safety_free_grid(t_map map);
void		get_pos(t_map *map);
int			init_flood_fill(t_map *map);

#endif