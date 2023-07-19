/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:17:51 by marvin            #+#    #+#             */
/*   Updated: 2023/07/19 12:37:48 by gacoelho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	end_game(t_game *game)
{
	free_map(game->map);
	mlx_destroy_image(game->mlx, game->info->img);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free_matrix_tex(game->info->texture);
	free_matrix_buf(game->info->buf);
	free(game->mlx);
	free(game->info);
	free(game);
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
		end_game(game);
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
