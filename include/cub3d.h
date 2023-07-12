/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:52 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/11 21:21:02 by jogomes-         ###   ########.fr       */
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
# define texSize 128

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
	double	texX;
	int		texY;
	double	step;
	double	texP;
	int		color;
}	t_time;

typedef struct s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	img;
	int		data;
	int		bits;
	int		line;
	int		endian;
	int		texture[4][texSize * texSize];
	int		buf[height][width];
	int		check_buf;
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
	void	*mlx_img;
	t_map	*map;
	t_map	*info;
}	t_game;

void	err_msg(const char *error);
void	check_map(t_map *map, const char *file);
void	check_floor_ceiling(t_map *map, char *line, char opt, int pos);
void	free_matrix(char **matrix);
int		**zero_buf(int **buf);
void	free_map(t_map *map);
void	save_map(t_map *map, char *line, int fd);
void	find_player(t_map *map, int line, int letter);
void	validate_map(t_map *map);
void    calc(t_info *info, t_game *game);
void	start_values(t_time *time, t_info *info, int i);
int		end_game(t_game *game);
void	print_info_map_test(t_map *map);

#endif