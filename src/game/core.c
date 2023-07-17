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
	if (time->ray_x < 0 && time->side == 0)
		return (info->texture[0][TEXSIZE * time->tex_y + time->tex_x]);
	if (time->ray_x >= 0 && time->side == 0)
		return (info->texture[1][TEXSIZE * time->tex_y + time->tex_x]);
	if (time->ray_y < 0 && time->side == 1)
		return (info->texture[2][TEXSIZE * time->tex_y + time->tex_x]);
	if (time->ray_y > 0 && time->side == 1)
		return (info->texture[3][TEXSIZE * time->tex_y + time->tex_x]);
	return (0);
}

static void	update_visual(t_game *game, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			info->data[i * WIDTH + j] = info->buf[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, info->img, 0, 0);
}

void	start_values(t_time *time, t_info *info, int i)
{
	time->camera = 2 * i / (double)WIDTH - 1;
	time->ray_x = info->dir_x + info->plane_x * time->camera;
	time->ray_y = info->dir_y + info->plane_y * time->camera;
	time->delta_x = fabs(1 / time->ray_x);
	time->delta_y = fabs(1 / time->ray_y);
	time->map_x = (int)info->pos_x;
	time->map_y = (int)info->pos_y;
	time->wall = 0;
}

int	core(t_game *game)
{
	calc(game->info, game);
	key_action(game, game->info);
	update_visual(game, game->info);
	return (0);
}
