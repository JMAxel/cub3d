/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:54:02 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/05 14:36:58 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

//REFAZER CHECAGEM DE TEXTURA GRAÇAS A MUDANÇAS NO PDF

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
