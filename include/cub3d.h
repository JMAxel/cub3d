/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:52 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/15 19:03:42 by jogomes-         ###   ########.fr       */
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
# define width 1280
# define height 720
# define texSize 100
# define K_W 119
# define K_A 97
# define K_S 115
# define K_D 100
# define K_ESC 65307

typedef struct s_time
{
	double	camera;
	double	rayX;
	double	rayY;
	double	sideX;
	double	sideY;
	double	deltaX;
	double	deltaY;
	double	wallDist;
	int		stepX;
	int		stepY;
	int		mapX;
	int		mapY;
	int		wall;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		tex;
	double	wallX;
	int		texX;
	int		texY;
	double	step;
	double	texP;
	int		color;
	double	rayX0;
	double	rayY0;
	double	rayX1;
	double	rayY1;
	int		mid;
	double	cameraV;
	double	row_dist;
	double	f_stepX;
	double	f_stepY;
}	t_time;

typedef struct s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*img;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
	int		texture[4][texSize * texSize];
	int		buf[height][width];
	int		check_buf;
	int		t_width;
	int		t_height;
	double	moveSpeed;
	double	rotSpeed;
	int		f_color;
	int		c_color;
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
void	free_matrix(char **matrix);
void	zero_buf(t_info *info);
void	free_map(t_map *map);
void	save_map(t_map *map, char *line, int fd);
void	find_player(t_map *map, int line, int letter, t_game *game);
void	validate_map(t_map *map, t_game *game);
void    creating_game(t_game *game, t_info *info);
int		core(t_game *game);
void    calc(t_info *info, t_game *game);
void    floor_calc(t_info *info, t_time *time);
int		check_texture(t_info *info, t_time *time);
void	start_values(t_time *time, t_info *info, int i);
int		key_action(int key, t_game *game);
int		end_game(t_game *game);
void	print_info_map_test(t_map *map);

#endif