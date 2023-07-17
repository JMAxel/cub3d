/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:54:10 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/17 02:54:42 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	start_key(t_game *game)
{
	game->info->key_w = 0;
	game->info->key_s = 0;
	game->info->key_a = 0;
	game->info->key_d = 0;
	game->info->key_ar_l = 0;
	game->info->key_ar_r = 0;
}

void	err_msg(const char *error)
{
	printf("Error\n");
	printf("%s", error);
	exit(1);
}
