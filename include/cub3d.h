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
    double	pos_i;
    double	pos_j;
    double	px;
    double	py;
    double	dist;
    int		bi;
    int		bj;
    int		gan;
    double	d;
    int		counter;
	int 	hit;
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
void	walls_in_sight(t_game *game, double degree);
void	set_DDA(t_game *game);
void	search_DDA(t_game *game);
void	hit_wall(t_game *game);

#endif