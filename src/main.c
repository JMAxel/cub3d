/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:19 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/12 20:43:41 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	zero_buf(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			info->buf[i][j++] = 0;
		i++;
	}
}

static void		zero_start(t_game *game)
{
	int	i;
	int	j;

	zero_buf(game->info);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < texSize * texSize)
			game->info->texture[i][j++] = 0;
		i++;
	}
	game->info->check_buf = 0;
	game->info->moveSpeed = 0.05;
	game->info->rotSpeed = 0.05;
}

static t_game	*start_variables(char *name)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->info = (t_info *)malloc(sizeof(t_info));
	check_map(game->map, name);
	zero_start(game);
	print_info_map_test(game->map);
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
	mlx_loop_hook(game->mlx, &core, game);
	mlx_hook(game->mlx_win, 2, 1L << 0, &key_action, game);
	mlx_loop(game->mlx);
	return (0);
}
