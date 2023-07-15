/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:01:31 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/11 15:01:31 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_texture(t_info *info, t_time *time)
{
	if (time->rayX < 0 && time->side == 0)
		return (info->texture[0][texSize * time->texY + time->texX]);
	if (time->rayX >= 0 && time->side == 0)
		return (info->texture[1][texSize * time->texY + time->texX]);
	if (time->rayY < 0 && time->side == 1)
		return (info->texture[2][texSize * time->texY + time->texX]);
	if (time->rayY > 0 && time->side == 1)
		return (info->texture[3][texSize * time->texY + time->texX]);
	return (0);
}

static void	update_visual(t_game *game, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			info->data[i * width + j] = info->buf[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, info->img, 0, 0);
}

void	start_values(t_time *time, t_info *info, int i)
{
	time->camera = 2 * i / (double)width - 1;
	time->rayX = info->dirX + info->planeX * time->camera;
	time->rayY = info->dirY + info->planeY * time->camera;
	time->deltaX = fabs(1 / time->rayX);
	time->deltaY = fabs(1 / time->rayY);
	time->mapX = (int)info->posX;
	time->mapY = (int)info->posY;
	time->wall = 0;
}

int core(t_game *game)
{
    calc(game->info, game);
    update_visual(game, game->info);
    return (0);
}