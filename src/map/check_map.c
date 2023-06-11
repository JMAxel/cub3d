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

static void	info_keeper(t_map *map, char *line, int fd)
{
	int	count;

	count = 0;
	while (count != 6)
	{
		if (ft_strnstr(line, "NO ", 3))
			
		else if (ft_strnstr(line, "SO ", 3))
		else if (ft_strnstr(line, "WE ", 3))
		else if (ft_strnstr(line, "EA ", 3))
	}
}

static void	check_map_addr(const char *file)
{
	if (!ft_strnstr((file + ft_strlen(file) - 4), ".cub", 4))
		err_msg("Invalid type of map. Please, use a '.cub' format\n");
}

void		check_map(t_map *map, const char *file)
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
