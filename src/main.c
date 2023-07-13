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

static int	input_checker(int key, t_game *game)
{
	if (key == 65307)
		end_game(game);
	else if (key == 119)
	{
		if(game->map->space[(int)(game->ray->pos_x + game->ray->dir_x)][(int)(game->ray->pos_y)] != '1')
			game->ray->pos_x += game->ray->dir_x;
		if(game->map->space[(int)(game->ray->pos_x)][(int)(game->ray->pos_y + game->ray->dir_y)] != '1')
			game->ray->pos_y += game->ray->dir_y;
		mlx_clear_window(game->mlx, game->mlx_win);
		raycasting(game);
	}
	else if (key == 115)
	{
		if(game->map->space[(int)(game->ray->pos_x - game->ray->dir_x)][(int)(game->ray->pos_y)] != '1')
			game->ray->pos_x -= game->ray->dir_x;
		if(game->map->space[(int)(game->ray->pos_x)][(int)(game->ray->pos_y - game->ray->dir_y)] != '1')
			game->ray->pos_y -= game->ray->dir_y;
		mlx_clear_window(game->mlx, game->mlx_win);
		raycasting(game);
	}
	else if(key == 97)
    {
      //both camera direction and camera plane must be rotated
	  //matrix transposta (positiva pra virar pra esquerda)
	  game->ray->dir_oldx = game->ray->dir_x;
	  game->ray->dir_x = game->ray->dir_x * cos(20*PI/180) - game->ray->dir_y * sin(20*PI/180);
      game->ray->dir_y = game->ray->dir_oldx * sin(20*PI/180) + game->ray->dir_y* cos(20*PI/180);
      game->ray->old_plane_x = game->ray->plane_x;
      game->ray->plane_x = game->ray->plane_x * cos(20*PI/180) - game->ray->plane_y * sin(20*PI/180);
      game->ray->plane_y = game->ray->old_plane_x * sin(20*PI/180) + game->ray->plane_y * cos(20*PI/180);
	  mlx_clear_window(game->mlx, game->mlx_win);
	  raycasting(game);
    }
	else if(key == 100)
    {
      //both camera direction and camera plane must be rotated
	  //matrix transposta (negativa pra virar pra direita)
      game->ray->dir_oldx = game->ray->dir_x;
      game->ray->dir_x = game->ray->dir_x * cos(-20*PI/180) - game->ray->dir_y * sin(-20*PI/180);
      game->ray->dir_y= game->ray->dir_oldx * sin(-20*PI/180) + game->ray->dir_y* cos(-20*PI/180);
      game->ray->old_plane_x = game->ray->plane_x;
      game->ray->plane_x = game->ray->plane_x * cos(-20*PI/180) - game->ray->plane_y * sin(-20*PI/180);
      game->ray->plane_y = game->ray->old_plane_x * sin(-20*PI/180) + game->ray->plane_y * cos(-20*PI/180);
	  mlx_clear_window(game->mlx, game->mlx_win);
	  raycasting(game);
    }
	else
		printf("key :: %d ", key);
	return (0);
}

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
	raycasting(game);
	mlx_key_hook(game->mlx_win, input_checker, game);
	mlx_hook(game->mlx_win, 17, 1L >> 2, end_game, game);
	mlx_loop(game->mlx);
	return (0);
}
