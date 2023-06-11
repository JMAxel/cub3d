/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:00:58 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/05 14:08:58 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*save_rgb_ceiling(t_map *map, char *info, int *rgb, int *pos)
{
	char	*nbr;

	nbr = ft_substr(info, 0, *pos);
	map->c_color[*rgb] = ft_atoi(nbr);
	printf("C -> %s | %d\n", nbr, map->c_color[*rgb]);
	*pos = *pos + 1;
	free(nbr);
	if (info[*pos])
	{
		nbr = ft_substr(info, *pos, ft_strlen(info) - *pos);
		free(info);
		*pos = 0;
		return (nbr);
	}
	else
		return (info);
}

static char	*save_rgb_floor(t_map *map, char *info, int *rgb, int *pos)
{
	char	*nbr;

	nbr = ft_substr(info, 0, *pos);
	map->f_color[*rgb] = ft_atoi(nbr);
	printf("F -> %s | %d\n", nbr, map->c_color[*rgb]);
	*pos = *pos + 1;
	free(nbr);
	if (info[*pos])
	{
		nbr = ft_substr(info, *pos, ft_strlen(info) - *pos);
		free(info);
		*pos = 0;
		return (nbr);
	}
	else
		return (info);
}

static void	check_ceiling(t_map *map, char *line)
{
	char	*info;
	int		rgb;
	int		pos;

	info = ft_substr(line, 2, ft_strlen(line) - 2);
	rgb = 0;
	pos = 0;
	while (info[pos])
	{
		if (info[pos] == ',' || info[pos + 1] == '\0')
			info = save_rgb_ceiling(map, info, &rgb, &pos);
		else
			pos++;
	}
	free(info);
}

static void	check_floor(t_map *map, char *line)
{
	char	*info;
	int		rgb;
	int		pos;

	info = ft_substr(line, 2, ft_strlen(line) - 2);
	rgb = 0;
	pos = 0;
	while (info[pos])
	{
		if (info[pos] == ',' || info[pos + 1] == '\0')
			info = save_rgb_floor(map, info, &rgb, &pos);
		else
			pos++;
	}
	free(info);
}

char		*check_floor_ceiling(t_map *map, char *line, int fd)
{
	check_floor(map, line);
	line = get_next_line(fd, 1);
	printf("test -> %s|\n", line);
	check_ceiling(map, line);
	line = get_next_line(fd, 1);
	return (line);
}