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
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = info->dirX;
	oldPlaneX = info->planeX;
	info->dirX = info->dirX * cos(info->rotSpeed)
		- info->dirY * sin(info->rotSpeed);
	info->dirX = oldDirX * sin(info->rotSpeed)
		+ info->dirY * cos(info->rotSpeed);
	info->planeX = info->planeX * cos(info->rotSpeed)
		- info->planeY * sin(info->rotSpeed);
	info->planeY = oldPlaneX * sin(info->rotSpeed)
		+ info->planeY * cos(info->rotSpeed);
}

static void	right_side(t_info *info)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = info->dirX;
	oldPlaneX = info->planeX;
	info->dirX = info->dirX * cos(-info->rotSpeed)
		- info->dirY * sin(-info->rotSpeed);
	info->dirX = oldDirX * sin(-info->rotSpeed)
		+ info->dirY * cos(-info->rotSpeed);
	info->planeX = info->planeX * cos(-info->rotSpeed)
		- info->planeY * sin(-info->rotSpeed);
	info->planeY = oldPlaneX * sin(-info->rotSpeed)
		+ info->planeY * cos(-info->rotSpeed);
}

static void	forward_and_back(int key, char **space, t_info *info)
{
	if (key == K_W)
	{
		if (!space[(int)(info->posX + info->dirX * info->moveSpeed)]
				[(int)(info->posY)])
			info->posX += info->dirX * info->moveSpeed;
		if (!space[(int)(info->posX)]
				[(int)(info->posY + info->dirY * info->moveSpeed)])
			info->posY += info->dirY * info->moveSpeed;
	}
	else
	{
		if (!space[(int)(info->posX - info->dirX * info->moveSpeed)]
				[(int)(info->posY)])
			info->posX -= info->dirX * info->moveSpeed;
		if (!space[(int)(info->posX)]
				[(int)(info->posY - info->dirY * info->moveSpeed)])
			info->posY -= info->dirY * info->moveSpeed;
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
	return(0);
}