/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:35:55 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/15 16:35:55 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	north_or_south(char letter, t_info *info)
{
	if (letter == 'N')
	{
		info->dir_x = -1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = 0.66;
	}
	if (letter == 'S')
	{
		info->dir_x = 1.0;
		info->dir_y = 0.0;
		info->plane_x = 0.0;
		info->plane_y = -0.66;
	}
	return (1);
}

static int	specify_player(char letter, t_info *info)
{
	if (letter == 'N' || letter == 'S')
		return (north_or_south(letter, info));
	if (letter == 'W')
	{
		info->dir_x = 0.0;
		info->dir_y = -1.0;
		info->plane_x = -0.66;
		info->plane_y = 0.0;
		return (1);
	}
	if (letter == 'E')
	{
		info->dir_x = 0.0;
		info->dir_y = 1.0;
		info->plane_x = 0.66;
		info->plane_y = 0.0;
		return (1);
	}
	return (0);
}

void	find_player(t_map *map, int line, int letter, t_game *game)
{
	while (map->space[line])
	{
		letter = 0;
		while (map->space[line][letter])
		{
			if (specify_player(map->space[line][letter], game->info))
			{
				map->player = 1;
				map->player_pos[0] = line;
				map->player_pos[1] = letter;
				return ;
			}
			letter++;
		}
		line++;
	}
	err_msg("No player was found.\n");
}
