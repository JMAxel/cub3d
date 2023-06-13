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
	//Refazer ideia para o salvar as informações
	//Provavelmente substituição de chamada de função por só uma linha
	if (ft_strnstr(line + pos, "NO", 2))
		no_option(map, line, pos);
	else if (ft_strnstr(line + pos, "SO", 2))
		so_option(map, line, pos);
	else if (ft_strnstr(line + pos, "WE", 2))
		we_option(map, line, pos);
	else if (ft_strnstr(line + pos, "EA", 2))
		ea_option(map, line, pos);
	else if (ft_strnstr(line + pos, "F", 1))
		check_floor_ceiling(map, line, "F");
	else if (ft_strnstr(line + pos, "C", 1))
		check_floor_ceiling(map, line, "C");
	else
		return (0)
	return (1);
}

static void	info_keeper(t_map *map, char *line, int fd)
{
	int count;
	int	pos;
	int aux;

	count = 0;
	while (count < 6)
	{
		pos = 0;
		aux = count;
		while (line[pos] == " " || line[pos] == "\t")
			pos++;
		count += find_info(t_map *map, char *line, int pos);
		if (line[pos] != "\n")
			err_msg("Wrong info order or Invalid info found\n");
		else if (aux == count)
			line = get_next_line(fd, 1);
		else
		{
			line = get_next_line(fd, 1);
			count++;
		}		
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
