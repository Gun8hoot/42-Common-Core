/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:02:24 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/01 14:30:01 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "external/gnl/get_next_line.h"
# include "external/libft/libft.h"
# include "external/minilibx-linux/mlx.h"
# include "external/minilibx-linux/mlx_int.h"
# include "external/printf/lib/ft_printf.h"
# include "mlx_code.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_load_image
{
	t_img			player;
	t_img			exit;
	t_img			wall;
	t_img			collectible;
}					t_load_image;

typedef struct s_map
{
	char			**flood_filled;
	char			**grid;
	char			*map_path;
	int				pos_player[2];
	int				pos_escape[2];
	int				collectible;
	int				map_size_x;
	int				map_size_y;
	int				counter;
	int				escape;
	int				player;
	int				*pos_x;
	int				*pos_y;
}					t_map;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map			map;
	t_load_image	image;
}					t_game;

bool				maps2arr(t_map *maps);
bool				maps_isvalid(t_map *map, char *map_path);
void				safety_free_grid(t_map map);
void				get_pos(t_map *map);
int					init_flood_fill(t_map *map);
bool				check_ext(t_map *map, char *file_path);
bool				render(t_game *game);
int					safety_exit(t_game game);

#endif