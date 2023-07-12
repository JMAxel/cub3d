/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:19 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/11 18:47:18 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		**zero_buf(int **buf)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			buf[i][j++] = 0;
		i++;
	}
	return (buf);
}

static void		zero_start(t_game *game)
{
	int	i;
	int	j;

	game->info->buf = zero_buf(game->info->buf);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			game->info->texture[i][j++] = 0;
		i++;
	}
	game->info->check_buf = 0;
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
	creating_game(game);
	return (game);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc != 2)
		err_msg("Invalid amount of arguments.\nUsage: ./cub3d example.cub\n");
	game = start_variables(argv[1]);
	mlx_loop_hook(game->mlx, &core, game);
	mlx_hook(game->mlx_win, 17, 1L << 0, &key_press, game);
	mlx_loop(game->mlx);
	return (0);
}
