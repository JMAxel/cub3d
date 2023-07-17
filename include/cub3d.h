/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:52 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/17 14:16:45 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# define WIDTH 1280
# define HEIGHT 720
# define TEXSIZE 100
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_AR_L 65361
# define K_AR_R 65363
# define K_ESC 65307

typedef struct s_time
{
	double	camera;
	double	ray_x;
	double	ray_y;
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	walldist;
	int		step_x;
	int		step_y;
	int		map_x;
	int		map_y;
	int		wall;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex;
	double	wall_x;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_p;
	int		color;
}	t_time;

typedef struct s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		**texture;
	int		**buf;
	int		check_buf;
	int		t_width;
	int		t_height;
	double	movespeed;
	double	rotspeed;
	int		f_color;
	int		c_color;
	int		key_w;
	int		key_s;
	int		key_a;
	int		key_d;
	int		key_ar_l;
	int		key_ar_r;
}	t_info;

typedef struct s_map
{
	char	**space;
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	int		f_color[3];
	int		c_color[3];
	int		player;
	int		player_pos[2];
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	t_info	*info;
}	t_game;

void	err_msg(const char *error);
void	check_map(t_map *map, const char *file, t_game *game);
void	check_floor_ceiling(t_map *map, char *line, char opt, int pos);
void	check_files(t_map *map);
void	check_format(t_map *map);
void	free_matrix(char **matrix);
void	zero_buf(t_info *info);
void	free_map(t_map *map);
void	save_map(t_map *map, char *line, int fd);
void	find_player(t_map *map, int line, int letter, t_game *game);
void	validate_map(t_map *map, t_game *game);
void	creating_game(t_game *game, t_info *info);
void	start_key(t_game *game);
int		core(t_game *game);
void	calc(t_info *info, t_game *game);
void	floor_calc(t_info *info, t_time *time);
int		check_texture(t_info *info, t_time *time);
void	start_values(t_time *time, t_info *info, int i);
int		key_action(t_game *game, t_info *info);
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
int		end_game(t_game *game);
void	print_info_map_test(t_map *map);

#endif