/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:19 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/15 23:26:32 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	start_tex_buf(t_info *info)
{
	int	i;

	i = 0;
	info->texture = ft_calloc(4, sizeof(int *));
	while (i < 4)
	{
		info->texture[i] = ft_calloc(TEXSIZE * TEXSIZE, sizeof(int));
		i++;
	}
	i = 0;
	info->buf = ft_calloc(HEIGHT, sizeof(int *));
	while (i < WIDTH)
	{
		info->buf[i] = ft_calloc(WIDTH, sizeof(int));
		i++;
	}
}

void	zero_buf(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
			info->buf[i][j++] = 0;
		i++;
	}
}

static void	zero_start(t_game *game)
{
	int	i;
	int	j;

	start_tex_buf(game->info);
	zero_buf(game->info);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < TEXSIZE * TEXSIZE)
			game->info->texture[i][j++] = 0;
		i++;
	}
	game->info->check_buf = 0;
	game->info->movespeed = 0.05;
	game->info->rotspeed = 0.05;
}

static t_game	*start_variables(char *name)
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	game->map = (t_map *)malloc(sizeof(t_map));
	game->info = (t_info *)malloc(sizeof(t_info));
	check_map(game->map, name, game);
	zero_start(game);
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
