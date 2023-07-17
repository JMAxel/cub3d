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

	i = time->draw_start;
	while (i < time->draw_end)
	{
		time->tex_y = (int)time->tex_p & (TEXSIZE - 1);
		time->tex_p += time->step;
		time->color = check_texture(info, time);
		if (time->side == 1)
			time->color = (time->color >> 1) & 8355711;
		info->buf[i][j] = time->color;
		info->check_buf = 1;
		i++;
	}
}

static void	prepare_draw(t_info *info, t_time *time, t_game *game)
{
	time->line_height = (int)(HEIGHT / time->walldist);
	time->draw_start = -time->line_height / 2 + HEIGHT / 2;
	if (time->draw_start < 0)
		time->draw_start = 0;
	time->draw_end = time->line_height / 2 + HEIGHT / 2;
	if (time->draw_end >= HEIGHT)
		time->draw_end = HEIGHT - 1;
	time->tex = game->map->space[time->map_x][time->map_y];
	if (time->side == 0)
		time->wall_x = info->pos_y + time->walldist * time->ray_y;
	else
		time->wall_x = info->pos_x + time->walldist * time->ray_x;
	time->wall_x -= floor(time->wall_x);
	time->tex_x = (int)(time->wall_x * (double)TEXSIZE);
	if (time->side == 0 && time->ray_x > 0)
		time->tex_x = TEXSIZE - time->tex_x - 1;
	if (time->side == 1 && time->ray_y < 0)
		time->tex_x = TEXSIZE - time->tex_x - 1;
	time->step = 1.0 * TEXSIZE / time->line_height;
	time->tex_p = (time->draw_start - HEIGHT / 2 + time->line_height / 2)
		* time->step;
}

static void	wall_side(t_info *info, t_time *time, t_game *game)
{
	while (time->wall == 0)
	{
		if (time->side_x < time->side_y)
		{
			time->side_x += time->delta_x;
			time->map_x += time->step_x;
			time->side = 0;
		}
		else
		{
			time->side_y += time->delta_y;
			time->map_y += time->step_y;
			time->side = 1;
		}
		if (game->map->space[time->map_x][time->map_y] == '1')
			time->wall = 1;
	}
	if (time->side == 0)
		time->walldist = (time->map_x - info->pos_x + (1 - time->step_x) / 2)
			/ time->ray_x;
	else
		time->walldist = (time->map_y - info->pos_y + (1 - time->step_y) / 2)
			/ time->ray_y;
}

static void	step_way(t_info *info, t_time *time)
{
	if (time->ray_x < 0)
	{
		time->step_x = -1;
		time->side_x = (info->pos_x - time->map_x) * time->delta_x;
	}
	else
	{
		time->step_x = 1;
		time->side_x = (time->map_x + 1.0 - info->pos_x) * time->delta_x;
	}
	if (time->ray_y < 0)
	{
		time->step_y = -1;
		time->side_y = (info->pos_y - time->map_y) * time->delta_y;
	}
	else
	{
		time->step_y = 1;
		time->side_y = (time->map_y + 1.0 - info->pos_y) * time->delta_y;
	}
}

void	calc(t_info *info, t_game *game)
{
	int		i;
	t_time	*time;

	i = 0;
	time = (t_time *)malloc(sizeof(t_time));
	if (info->check_buf == 1)
		zero_buf(info);
	floor_calc(info, time);
	while (i < WIDTH)
	{
		start_values(time, info, i);
		step_way(info, time);
		wall_side(info, time, game);
		prepare_draw(info, time, game);
		final_calc(info, time, i);
		i++;
	}
	free(time);
}
