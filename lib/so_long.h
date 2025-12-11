/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nclavel <nclavel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 10:02:24 by nclavel           #+#    #+#             */
/*   Updated: 2025/12/11 13:57:13 by nclavel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// --- INCLUDE ---
# include "external/gnl/get_next_line.h"
# include "external/libft/libft.h"
# include "external/minilibx-linux/mlx.h"
# include "external/minilibx-linux/mlx_int.h"
# include "external/printf/lib/ft_printf.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// --- DEFINE ---
# define HEIGHT 64
# define WIDTH 64
# define ON_DESTROY 17
# define ON_KEYDOWN 2
# define ESC 0xff1b
# define KEY_W 0x77
# define KEY_S 0x73
# define KEY_A 0x61
# define KEY_D 0x64
# define KEY_UP 0xff52
# define KEY_DOWN 0xff54
# define KEY_LEFT 0xff51
# define KEY_RIGHT 0xff53

// --- STRUCTURE ---
typedef struct s_image
{
	void			*ptr;
	int				width;
	int				height;
}					t_image;

typedef struct s_load_image
{
	t_image			pict;
}					t_load_image;

typedef struct s_map
{
	char			**flood_filled;
	char			**grid;
	char			*map_path;
	int				pos_player[2];
	int				pos_escape[2];
	int				collectible;
	int				collec_pick_up;
	int				show_escape;
	int				map_size_x;
	int				map_size_y;
	int				counter;
	int				escape;
	int				player;
	int				pos_x;
	int				pos_y;
}					t_map;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			looking_on;
	bool			loop;
	t_map			map;
	t_load_image	image;
}					t_game;

// --- PROTOTYPE ---
bool				maps_isvalid(t_map *map, char *map_path);
bool				check_ext(t_map *map, char *file_path);
bool				dup_grid(t_map *map, char **grid);
bool				init_map(t_map *maps);
bool				init_flood_fill(t_map *map);
void				flood_fill(t_map *map, int pos_x, int pos_y, int *col);
void				find_elem(t_map *map);

// --- RENDER ---
bool				gen_frame(t_game *game);
bool				render(t_game *game);
void				show_map(char **map);

// --- LOGIC ---
int					keypress_action(int key, t_game *game);
bool				anti_oob(char c);
void				check_event(t_game *game, int pos_x, int pos_y);

// --- FREE ALL ---
void				safety_free_grid(char **grid, char **flood_grid);
void				free_picture(t_game game, t_load_image images);
int					safety_exit_all(t_game *game);
int					safety_close(t_game *game);

#endif