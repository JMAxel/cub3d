/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:32:13 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/12 19:32:13 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	left_side(t_info *info, t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	old_plane_x = info->plane_x;
	info->dir_x = info->dir_x * cos(info->rotspeed)
		- info->dir_y * sin(info->rotspeed);
	info->dir_y = old_dir_x * sin(info->rotspeed)
		+ info->dir_y * cos(info->rotspeed);
	info->plane_x = info->plane_x * cos(info->rotspeed)
		- info->plane_y * sin(info->rotspeed);
	info->plane_y = old_plane_x * sin(info->rotspeed)
		+ info->plane_y * cos(info->rotspeed);
	mlx_clear_window(game->mlx, game->mlx_win);
}

static void	right_side(t_info *info, t_game *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dir_x;
	old_plane_x = info->plane_x;
	info->dir_x = info->dir_x * cos(-info->rotspeed)
		- info->dir_y * sin(-info->rotspeed);
	info->dir_y = old_dir_x * sin(-info->rotspeed)
		+ info->dir_y * cos(-info->rotspeed);
	info->plane_x = info->plane_x * cos(-info->rotspeed)
		- info->plane_y * sin(-info->rotspeed);
	info->plane_y = old_plane_x * sin(-info->rotspeed)
		+ info->plane_y * cos(-info->rotspeed);
	mlx_clear_window(game->mlx, game->mlx_win);
}

static void	right_and_left(char **space, t_info *info, t_game *game)
{
	if (info->key_a)
	{
		if (space[(int)(info->pos_x)]
				[(int)(info->pos_y + info->dir_x * info->movespeed)] != '1')
			info->pos_y += info->dir_x * info->movespeed;
		if (space[(int)(info->pos_x - info->dir_y * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x -= info->dir_y * info->movespeed;
	}
	else
	{
		if (space[(int)(info->pos_x)]
				[(int)(info->pos_y - info->dir_x * info->movespeed)] != '1')
			info->pos_y -= info->dir_x * info->movespeed;
		if (space[(int)(info->pos_x + info->dir_y * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x += info->dir_y * info->movespeed;
	}
	mlx_clear_window(game->mlx, game->mlx_win);
}

static void	forward_and_back(char **space, t_info *info, t_game *game)
{
	if (info->key_w)
	{
		if (space[(int)(info->pos_x + info->dir_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x += info->dir_x * info->movespeed;
		if (space[(int)(info->pos_x)]
				[(int)(info->pos_y + info->dir_y * info->movespeed)] != '1')
			info->pos_y += info->dir_y * info->movespeed;
	}
	else
	{
		if (space[(int)(info->pos_x - info->dir_x * info->movespeed)]
				[(int)(info->pos_y)] != '1')
			info->pos_x -= info->dir_x * info->movespeed;
		if (space[(int)(info->pos_x)]
				[(int)(info->pos_y - info->dir_y * info->movespeed)] != '1')
			info->pos_y -= info->dir_y * info->movespeed;
	}
	mlx_clear_window(game->mlx, game->mlx_win);
}

int	key_action(t_game *game, t_info *info)
{
	if (info->key_w || info->key_s)
		forward_and_back(game->map->space, game->info, game);
	if (info->key_a || info->key_d)
		right_and_left(game->map->space, game->info, game);
	if (info->key_ar_r)
		right_side(game->info, game);
	if (info->key_ar_l)
		left_side(game->info, game);
	return (0);
}
