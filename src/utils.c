/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:17:51 by marvin            #+#    #+#             */
/*   Updated: 2023/06/14 21:17:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_matrix(char **matrix)
{
	int	count;

	count = 0;
	while (matrix[count])
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

int	end_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
	return (0);
}

void	print_info_map_test(t_map *map)
{
	int	i;

	i = 0;
	printf("%s\n", map->no_tex);
	printf("%s\n", map->so_tex);
	printf("%s\n", map->we_tex);
	printf("%s\n", map->ea_tex);
	printf("%d %d %d\n", map->f_color[0], map->f_color[1], map->f_color[2]);
	printf("%d %d %d\n\n", map->c_color[0], map->c_color[1], map->c_color[2]);
	while (map->space[i])
	{
		printf("%s\n", map->space[i]);
		i++;
	}
	printf("It works!\n");
}
