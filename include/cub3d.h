/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:38:52 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/14 23:04:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_map
{
	char	**space;
	char	*no_tex;
	char	*so_tex;
	char	*we_tex;
	char	*ea_tex;
	int		f_color[3];
	int		c_color[3];
}	t_map;

void	err_msg(const char *error);
void	check_map(t_map *map, const char *file);
void	check_floor_ceiling(t_map *map, char *line, char opt, int pos);
void	free_matrix(char **matrix);
void	save_map(t_map *map, char *line, int fd);

#endif