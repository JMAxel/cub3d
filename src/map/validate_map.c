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

static void	validate_individual(char letter, t_map *map)
{
	if (letter == ' ')
		return ;
	if (letter == '1')
		return ;
	if (letter == '0')
		return ;
	if (letter == map->space[map->player_pos[0]][map->player_pos[1]])
	{
		if (map->player == 2)
			err_msg("Two or more players were found.\n");
		else
			map->player = 2;
		return ;
	}
	err_msg("Invalid map info.\n");
}

static int	validate_inside(char **space, int line, t_map *map)
{
	unsigned int	letter;

	letter = 0;
	while (space[line])
	{
		letter = 0;
		while (space[line][letter])
		{
			if (letter == 0 || letter == ft_strlen(space[line]))
			{
				if (space[line][letter] != '1' && space[line][letter] != ' ')
					err_msg("Invalid map info.\n");
			}
			else
				validate_individual(space[line][letter], map);
			letter++;
		}
		line++;
	}
	return (line - 1);
}

static int	validate_wall(char **space, int line, int letter)
{
	while (space[line][letter])
	{
		if (space[line][letter] != '1' && space[line][letter] != ' ')
			err_msg("Invalid map info.\n");
		letter++;
	}
	return (line + 1);
}

void	validate_map(t_map *map)
{
	int	line;
	int	letter;

	line = 0;
	letter = 0;
	find_player(map, line, letter);
	line = validate_wall(map->space, line, letter);
	line = validate_inside(map->space, line, map);
	validate_wall(map->space, line, letter);
}
