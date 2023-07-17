/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:19 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/19 18:13:18 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_game	*start_variables(char *name)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	game->info = (t_info *)malloc(sizeof(t_info));
	check_map(game->map, name);
	zero_start(game);
	init_ray(game);
	game->mlx = mlx_init();
	creating_game(game, game->info);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		err_msg("Invalid amount of arguments.\nUsage: ./cub3d example.cub\n");
	game = start_variables(argv[1]);
	mlx_loop_hook(game->mlx, &raycasting, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->mlx_win, 3, 1L << 1, &key_release, game);
	mlx_hook(game->mlx_win, 17, 1L >> 2, end_game, game);
	mlx_loop(game->mlx);
	return (0);
}
