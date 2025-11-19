/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:02:24 by nclavel           #+#    #+#             */
/*   Updated: 2025/11/18 17:07:58 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include "external/gnl/get_next_line.h"
# include "external/minilibx-linux/mlx.h"
# include "external/minilibx-linux/mlx_int.h"
# include "external/printf/lib/ft_printf.h"
# include "external/libft/libft.h"

typedef struct s_logic
{
	int	*pos_x;
	int	*pos_y;
} t_logic;

typedef struct s_map
{
	char	*map_path;
	char	**grid;
	int		collectible;
	int		map_size_x;
	int		map_size_y;
	int		player;
	int		escape;
} t_map;

bool	maps2arr(t_map *maps, char *map_path);
bool	maps_isvalid(t_map *map, char *map_path);

#endif