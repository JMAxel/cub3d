/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 17:00:13 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/17 17:00:13 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_matrix(char **matrix)
{
	int	count;

	count = 0;
	while (matrix[count] != NULL)
	{
		free(matrix[count]);
		count++;
	}
	free(matrix);
}

void	free_matrix_tex(int **matrix)
{
	int	count;

	count = 0;
	while (count < 4)
	{
		free(matrix[count]);
		count++;
	}
	free(matrix);
}

void	free_matrix_buf(int **matrix)
{
	int	count;

	count = 0;
	while (count < HEIGHT)
	{
		free(matrix[count]);
		count++;
	}
	free(matrix);
}

void	free_map(t_map *map)
{
	free(map->no_tex);
	free(map->so_tex);
	free(map->we_tex);
	free(map->ea_tex);
	free_matrix(map->space);
	free(map);
}
