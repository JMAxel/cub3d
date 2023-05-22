/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:54:02 by jogomes-          #+#    #+#             */
/*   Updated: 2023/05/22 17:12:35 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	save_texture(t_map *map, char *line, int count)
{
	if (ft_strnstr(line, "NO ", 3) && count == 0)
	{
		map->no_tex = ft_strdup(line + 3);
		map->no_tex[ft_strlen(line) - 4] = '\0';
	}
	else if (ft_strnstr(line, "SO ", 3) && count == 1)
	{
		map->so_tex = ft_strdup(line + 3);
		map->so_tex[ft_strlen(line) - 4] = '\0';
	}
	else if (ft_strnstr(line, "WE ", 3) && count == 2)
	{
		map->we_tex = ft_strdup(line + 3);
		map->we_tex[ft_strlen(line) - 4] = '\0';
	}
	else if (ft_strnstr(line, "EA ", 3) && count == 3)
	{
		map->ea_tex = ft_strdup(line + 3);
		map->ea_tex[ft_strlen(line) - 4] = '\0';
	}
	else
		err_msg("Invalid address or texture\n");
}

char	*check_texture(t_map *map, char *line, int fd)
{
	int	count;

	count = 0;
	while (line)
	{
		save_texture(map, line, count);
		line = get_next_line(fd, 1);
		count++;
		if (count == 4)
			break ;
	}
	line = get_next_line(fd, 1);
	return (line);
}
