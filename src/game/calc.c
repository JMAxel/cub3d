/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:04:18 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/11 15:04:18 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	final_calc(t_info *info, t_time *time, int j)
{
	int	i;

	i = time->drawStart;
	while (i < time->drawEnd)
	{
		time->texY = (int)time->texP & (texSize - 1);
		time->texP += time->step;
		time->color =
				info->texture[tex][texSize * time->texY + time->texX];
		if (time->side == 1)
			time->color = (time->color >> 1) & 8355711;
		info->buf[i][j] = time->color;
		info->check_buf = 1;
		i++;
	}
}

static void	prepare_draw(t_info *info, t_time *time, t_game *game)
{
	time->lineHeight = (int)(height / time->wallDist);
	time->drawStart = -time->lineHeight / 2 + height / 2;
	if (time->drawStart < 0)
		time->drawStart = 0;
	time->drawEnd = time->lineHeight / 2 + height / 2;
	if (time->drawEnd >= height)
		time->drawEnd = height - 1;
	time->tex = game->map->space[time->mapX][time->mapY];
	if (time->side == 0)
		time->wallX = info->posY + time->wallDist * time->rayY;
	else
		time->wallX = info->posX + time->wallDist * time->rayX;
	time->wallX -= floor(time->wallX);
	time->texX = (int)(time->wallX * (double)texSize);
	if (time->side == 0 && time->rayX > 0)
		time->texX = texSize - time->texX - 1;
	if (time->side == 1 && time->rayY < 0)
		time->texX = texSize - time->texX - 1;
	time->step = 1.0 * texSize / time->lineHeight;
	time->texP = (time->drawStart - height / 2 + time->lineHeight / 2) *
			time->step;
}

static void	wall_side(t_info *info, t_time *time, t_game *game)
{
	while (time->wall == 0)
	{
		if (time->sideX < time->sideY)
		{
			time->sideX += time->deltaX;
			time->mapX += time->stepX;
			time->side = 0;
		}
		else
		{
			time->sideY += time->deltaY;
			time->mapY += time->stepY;
			time->side = 1;
		}
		if (game->map->space[time->mapX][time->mapY] == '1')
			time->wall = 1;
	}
	if (time->side == 0)
		time->wallDist = (time->mapX - info->posX + (1 - time->stepX) / 2) /
			time->rayX;
	else
		time->wallDist = (time->mapY - info->posY + (1 - time->stepY) / 2) /
			time->rayY;
}

static void	step_way(t_info *info, t_time *time)
{
	if (time->rayX < 0)
	{
		time->stepX = -1;
		time->sideX = (info->posX - time->mapX) * time->deltaX;
	}
	else
	{
		time->stepX = 1;
		time->sideX = (time->mapX + 1.0 - info->posX) * time->deltaX;
	}
	if (time->rayY < 0)
	{
		time->stepY = -1;
		time->sideY = (info->posY - time->mapY) * time->deltaY;
	}
	else
	{
		time->stepY = 1;
		time->sideY = (time->mapY + 1.0 - info->posY) * time->deltaY;
	}
}

void    calc(t_info *info, t_game *game)
{
	int i;
	t_time *time;

	i = 0;
	time = (t_time *)malloc(sizeof(t_time));
	if (info->check_buf == 1)
		zero_buf(info);
	while (i < width)
	{
		start_values(time, info, i);
		step_way(info, time);
		wall_side(info, time, game);
		prepare_draw(info, time, game);
		final_calc(info, time, i);
		i++;
	}
}