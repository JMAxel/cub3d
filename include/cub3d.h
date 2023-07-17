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

# define TEXSIZE 100
# define W 1280
# define H 720

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
	double	dir_oldx;
	double	plane_x;
	double	old_plane_x;
	double	plane_y;
	double	camera_x;
	double	r_dirx;
	double	r_diry;
	double	walldist;
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

typedef struct s_info
{
	int		w;
	int		s;
	int		d;
	int		a;

	int		tex;
	int		tex_x;
	int		tex_y;
	int		tex_p;
	int		color;
	double	step;
	double	wall_x;


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

	int		f_color;
	int		c_color;
}	t_info;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
	t_ray	*ray;
	t_info	*info;

}	t_game;


//validação de mapa
void	err_msg(const char *error);
void	check_map(t_map *map, const char *file);
void	check_floor_ceiling(t_map *map, char *line, char opt, int pos);
void	save_map(t_map *map, char *line, int fd);
void	find_player(t_map *map, int line, int letter);
void	validate_map(t_map *map);
void	print_info_map_test(t_map *map);
//renderizar o jogo
int		raycasting(t_game *game);
void	init_ray(t_game *game);
void	camera(t_game *game, t_ray *ray);
void	DDA_set(t_ray *ray);
void	set_side(t_ray *ray);
void	DDA_search(t_game *game, t_ray *ray);
//texture
int		check_texture(t_info *info, t_ray *ray);
void	start_tex_buf(t_info *info);
void	zero_buf(t_info *info);
void	zero_start(t_game *game);
void	prepare_draw(t_game *game, t_ray *ray, t_info *info);
void	draw_wall(t_ray *ray, t_info *info, int x);
void	floor_calc(t_info *info);
void	update_visual(t_game *game, t_info *info);
void	creating_game(t_game *game, t_info *info);
//keys and hooks
int		key_press(int key, t_game *game);
int		key_release(int key, t_game *game);
void	right_key(t_game *game);
void	left_key(t_game *game);
void	down_key(t_game *game);
void	up_key(t_game *game);
//limpeza de memoria e finalização do jogo
void	free_matrix(char **matrix);
void	free_map(t_map *map);
int		end_game(t_game *game);
#endif