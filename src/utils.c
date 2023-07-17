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

int	key_press(int key, t_game *game)
{
	if (key == K_W)
		game->info->key_w = 1;
	else if (key == K_S)
		game->info->key_s = 1;
	else if (key == K_A)
		game->info->key_a = 1;
	else if (key == K_D)
		game->info->key_d = 1;
	else if (key == K_AR_L)
		game->info->key_ar_l = 1;
	else if (key == K_AR_R)
		game->info->key_ar_r = 1;
	else if (key == K_ESC)
		exit(0);
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == K_W)
		game->info->key_w = 0;
	else if (key == K_S)
		game->info->key_s = 0;
	else if (key == K_A)
		game->info->key_a = 0;
	else if (key == K_D)
		game->info->key_d = 0;
	else if (key == K_AR_L)
		game->info->key_ar_l = 0;
	else if (key == K_AR_R)
		game->info->key_ar_r = 0;
	return (0);
}
