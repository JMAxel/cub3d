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

/*static int	input_checker(int key, t_game *game)
{
	if (key == 65307)
		end_game(game);
	return (0);
}*/

static t_game	*start_variables(char *name)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->ray = (t_ray *)malloc(sizeof(t_ray));
	check_map(game->map, name);
	print_info_map_test(game->map);
	//game->mlx = mlx_init();
	//game->mlx_win = mlx_new_window(game->mlx, 1280, 720, "cub3d");
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		err_msg("Invalid amount of arguments.\nUsage: ./cub3d example.cub\n");
	game = start_variables(argv[1]);
	raycasting(game);
	/*mlx_key_hook(game->mlx_win, input_checker, game);
	mlx_hook(game->mlx_win, 17, 1L >> 2, end_game, game);
	mlx_loop(game->mlx);*/
	return (0);
}
