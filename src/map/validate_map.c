/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:23:46 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/15 16:23:46 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	check_files(t_map *map)
{
	int	fd;

	check_format(map);
	fd = open(map->no_tex, O_RDONLY);
	if (fd == -1)
		err_msg("Invalid path to texture.\n");
	close(fd);
	fd = open(map->so_tex, O_RDONLY);
	if (fd == -1)
		err_msg("Invalid path to texture.\n");
	close(fd);
	fd = open(map->we_tex, O_RDONLY);
	if (fd == -1)
		err_msg("Invalid path to texture.\n");
	close(fd);
	fd = open(map->ea_tex, O_RDONLY);
	if (fd == -1)
		err_msg("Invalid path to texture.\n");
	close(fd);
}

static int	flood_fill(char **space, int x, int y)
{
	int	s[8];

	if (y < 0 || x < 0 || space[x][y] == ' ' || space[x][y] == 0
		|| space[x] == 0)
		return (0);
	else if (space[x][y] == '1' || space[x][y] == '.')
		return (1);
	space[x][y] = '.';
	s[0] = flood_fill(space, x, y + 1);
	s[1] = flood_fill(space, x, y - 1);
	s[2] = flood_fill(space, x + 1, y);
	s[3] = flood_fill(space, x - 1, y);
	s[4] = flood_fill(space, x + 1, y + 1);
	s[5] = flood_fill(space, x + 1, y - 1);
	s[6] = flood_fill(space, x + 1, y + 1);
	s[7] = flood_fill(space, x - 1, y + 1);
	return (s[0] && s[1] && s[2] && s[3] && s[4] && s[5] && s[6] && s[7]);
}

void	validate_map(t_map *map, t_game *game)
{
	find_player(map, 0, 0, game);
	if (!flood_fill(map->space, map->player_pos[0], map->player_pos[1]))
		err_msg("Invalid walls.\n");
}
