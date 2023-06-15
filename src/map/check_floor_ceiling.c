/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_ceiling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 16:24:26 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/15 18:35:11 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*info_update(char *info, char *single_nbr)
{
	char	*new_info;
	int		start;
	int		len;

	start = ft_strlen(single_nbr) + 1;
	len = ft_strlen(info);
	new_info = ft_substr(info, start, len - 3);
	free(info);
	free(single_nbr);
	return (new_info);
}

char	*single_value(char *info, char *single_nbr)
{
	if (ft_strchr(info, ','))
		single_nbr = ft_substr(info, 0,
				ft_strlen(info) - ft_strlen(ft_strchr(info, ',')));
	else
		single_nbr = ft_strdup(info);
	return (single_nbr);
}

void	check_floor_ceiling(t_map *map, char *line, char opt, int pos)
{
	char	*info;
	char	*single_nbr;
	int		nbr;	

	nbr = 0;
	info = ft_substr(line, pos + 2, ft_strlen(line) - pos - 3);
	while (nbr < 3)
	{
		single_nbr = single_value(info, single_nbr);
		if (ft_atoi(single_nbr) >= 0 && ft_atoi(single_nbr) < 256)
		{
			if (opt == 'F')
				map->f_color[nbr] = ft_atoi(single_nbr);
			else
				map->c_color[nbr] = ft_atoi(single_nbr);
			nbr++;
		}
		else
			err_msg("Invalid number for floor or ceiling.\n");
		info = info_update(info, single_nbr);
	}
	free(info);
}
