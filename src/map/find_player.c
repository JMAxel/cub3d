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

static int	specify_player(char letter)
{
	if (letter == 'N')
		return (1);
	if (letter == 'S')
		return (1);
	if (letter == 'W')
		return (1);
	if (letter == 'E')
		return (1);
	return (0);
}

void	find_player(t_map *map, int line, int letter)
{
	while (map->space[line])
	{
		letter = 0;
		while (map->space[line][letter])
		{
			if (specify_player(map->space[line][letter]))
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
