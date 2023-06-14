/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:07:17 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/05 14:36:08 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	find_info(t_map *map, char *line, int pos)
{
	if (ft_strnstr(line + pos, "NO", 2))
		map->no_tex = ft_substr(line, pos + 3, ft_strlen(line) - pos - 4);
	else if (ft_strnstr(line + pos, "SO", 2))
		map->so_tex = ft_substr(line, pos + 3, ft_strlen(line) - pos - 4);
	else if (ft_strnstr(line + pos, "WE", 2))
		map->we_tex = ft_substr(line, pos + 3, ft_strlen(line) - pos - 4);
	else if (ft_strnstr(line + pos, "EA", 2))
		map->ea_tex = ft_substr(line, pos + 3, ft_strlen(line) - pos - 4);
	else if (ft_strnstr(line + pos, "F", 1))
		check_floor_ceiling(map, line, 'F', pos);
	else if (ft_strnstr(line + pos, "C", 1))
		check_floor_ceiling(map, line, 'C', pos);
	else
		return (0);
	return (1);
}

static void	info_keeper(t_map *map, char *line, int fd)
{
	int	count;
	int	pos;

	count = 0;
	while (count < 6)
	{
		pos = 0;
		while (line[pos] == ' ' || line[pos] == '\t')
			pos++;
		if (line[pos] == '1')
			err_msg("Map info was found before other parameters.\n");
		count += find_info(map, line, pos);
		free(line);
		line = get_next_line(fd, 1);
		if (!line)
			err_msg("Something went wrong while analyzing info.\n");
	}
	free(line);
}

static void	check_map_addr(const char *file)
{
	if (!ft_strnstr((file + ft_strlen(file) - 4), ".cub", 4))
		err_msg("Invalid type of map. Please, use a '.cub' format\n");
}

void	check_map(t_map *map, const char *file)
{
	int		fd;
	char	*line;

	check_map_addr(file);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		err_msg("No map file was found\n");
	line = get_next_line(fd, 1);
	info_keeper(map, line, fd);
	close(fd);
}
