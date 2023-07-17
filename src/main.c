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
	check_map(game->map, name);
	print_info_map_test(game->map);
	game->ray->pos_x = game->map->player_pos[0]; //x posição inicial no grind;
	game->ray->pos_y = game->map->player_pos[1]; //y posição inicial no grind;
	game->ray->dir_x = -1;//direção inicial do vetor x;
	game->ray->dir_y = 0;//direção inicial do vetor y;
	game->ray->plane_x = 0; // projeção no plano da camera;
	game->ray->plane_y = 0.66; // FOV de 0.66;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1280, 720, "cub3d");
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
