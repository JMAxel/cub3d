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

static void	left_side(t_info *info)
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
}

static void	right_side(t_info *info)
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
}

static void	forward_and_back(int key, char **space, t_info *info)
{
	if (key == K_W)
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
}

int	key_action(int key, t_game *game)
{
	if (key == K_W || key == K_S)
		forward_and_back(key, game->map->space, game->info);
	if (key == K_D)
		right_side(game->info);
	if (key == K_A)
		left_side(game->info);
	if (key == K_ESC)
		exit(0);
	mlx_clear_window(game->mlx, game->mlx_win);
	core(game);
	return (0);
}
