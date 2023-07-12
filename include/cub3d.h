/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:52 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/20 14:50:55 by jogomes-         ###   ########.fr       */
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

# define PI 3.14159265
# define w 640
# define h 480

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

typedef struct s_ray
{
    double	pos_x;
    double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	r_dirx;
	double	r_diry;
	double	perpwalldist;
	double	dist_xside;
	double	dist_yside;
	double	delta_x;
	double	delta_y;
	int		stepx;
	int		stepy;
	int		mapx;
	int		mapy;
	int		hit;
	int		side;
	int		lineheight;
	int		drawstart;
	int		drawend;
}	t_ray;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	t_ray	*ray;

}	t_game;

void	err_msg(const char *error);
void	check_map(t_map *map, const char *file);
void	check_floor_ceiling(t_map *map, char *line, char opt, int pos);
void	free_matrix(char **matrix);
void	free_map(t_map *map);
void	save_map(t_map *map, char *line, int fd);
void	find_player(t_map *map, int line, int letter);
void	validate_map(t_map *map);
int		end_game(t_game *game);
void	print_info_map_test(t_map *map);


void	raycasting(t_game *game);
void	camera(t_game *game);
void	DDA_set(t_ray *ray);
void	set_side(t_ray *ray);
void	DDA_search(t_game *game);
#endif