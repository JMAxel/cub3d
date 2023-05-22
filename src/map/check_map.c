/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:07:17 by jogomes-          #+#    #+#             */
/*   Updated: 2023/05/22 17:10:34 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	line = check_texture(map, line, fd);
/* 	line = check_floor_ceiling(map, line, fd); */
	close(fd);
}
