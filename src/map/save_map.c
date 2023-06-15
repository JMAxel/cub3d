/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 19:14:01 by marvin            #+#    #+#             */
/*   Updated: 2023/06/14 19:14:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	**reallocate_space(int value, char **space)
{
	char	**aux;
	int		count;

	count = 0;
	aux = ft_calloc(value, sizeof(char *));
	while (count < value - 2)
	{
		aux[count] = ft_strdup(space[count]);
		count++;
	}
	free_matrix(space);
	return (aux);
}

static char	*line_to_answer(char *line, char *answer)
{
	unsigned int	line_pos;
	unsigned int	ans_pos;
	int				tab_count;

	line_pos = 0;
	ans_pos = 0;
	while (line_pos < ft_strlen(line))
	{
		if (line[line_pos] == '\t')
		{
			tab_count = 0;
			while (tab_count < 4)
			{
				answer[ans_pos++] = ' ';
				tab_count++;
			}
			line_pos++;
		}
		else
			answer[ans_pos++] = line[line_pos++];
	}
	return (answer);
}

static char	*format_string(char *line)
{
	unsigned int	pos;
	int				tabs;
	char			*answer;

	pos = 0;
	tabs = 0;
	while (pos < ft_strlen(line))
	{
		if (line[pos] == '\t')
			tabs++;
		pos++;
	}
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	answer = ft_calloc((ft_strlen(line) - tabs + 1) + (tabs * 4), sizeof(char));
	return (line_to_answer(line, answer));
}

static void	map_to_space(t_map *map, char *line, int fd)
{
	int	pos;

	pos = 0;
	map->space = ft_calloc(2, sizeof(char *));
	while (42)
	{
		map->space[pos] = format_string(line);
		pos++;
		free(line);
		line = get_next_line(fd, 1);
		if (!line)
			break ;
		map->space = reallocate_space(pos + 2, map->space);
	}
}

void	save_map(t_map *map, char *line, int fd)
{
	int	pos;

	line = get_next_line(fd, 1);
	while (42)
	{
		pos = 0;
		while (line[pos] == '\t' || line[pos] == ' ')
			pos++;
		if (line[pos] == '\n')
			line = get_next_line(fd, 1);
		else
			break ;
	}
	if (line[pos] == '1')
		map_to_space(map, line, fd);
	else
		err_msg("Wrong info inside map.\n");
	free(line);
}
