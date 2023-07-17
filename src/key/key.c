#include "../../include/cub3d.h"

void up_key(t_game *game)
{
    if(game->map->space[(int)(game->ray->pos_x + game->ray->dir_x * 0.1)][(int)(game->ray->pos_y)] != '1')
		game->ray->pos_x += game->ray->dir_x * 0.1;
	if(game->map->space[(int)(game->ray->pos_x)][(int)(game->ray->pos_y + game->ray->dir_y * 0.1)] != '1')
		game->ray->pos_y += game->ray->dir_y * 0.1;
	mlx_clear_window(game->mlx, game->mlx_win);
}

void down_key(t_game *game)
{
    if(game->map->space[(int)(game->ray->pos_x - game->ray->dir_x)][(int)(game->ray->pos_y)] != '1')
	    game->ray->pos_x -= game->ray->dir_x;
	if(game->map->space[(int)(game->ray->pos_x)][(int)(game->ray->pos_y - game->ray->dir_y)] != '1')
		game->ray->pos_y -= game->ray->dir_y;
	mlx_clear_window(game->mlx, game->mlx_win);
}

void left_key(t_game *game)
{
    game->ray->dir_oldx = game->ray->dir_x;
	game->ray->dir_x = game->ray->dir_x * cos(5*PI/180) - game->ray->dir_y * sin(5*PI/180);
    game->ray->dir_y = game->ray->dir_oldx * sin(5*PI/180) + game->ray->dir_y* cos(5*PI/180);
    game->ray->old_plane_x = game->ray->plane_x;
    game->ray->plane_x = game->ray->plane_x * cos(5*PI/180) - game->ray->plane_y * sin(5*PI/180);
    game->ray->plane_y = game->ray->old_plane_x * sin(5*PI/180) + game->ray->plane_y * cos(5*PI/180);
	mlx_clear_window(game->mlx, game->mlx_win);
}

void right_key(t_game *game)
{
    game->ray->dir_oldx = game->ray->dir_x;
    game->ray->dir_x = game->ray->dir_x * cos(-5*PI/180) - game->ray->dir_y * sin(-5*PI/180);
    game->ray->dir_y = game->ray->dir_oldx * sin(-5*PI/180) + game->ray->dir_y* cos(-5*PI/180);
    game->ray->old_plane_x = game->ray->plane_x;
    game->ray->plane_x = game->ray->plane_x * cos(-5*PI/180) - game->ray->plane_y * sin(-5*PI/180);
    game->ray->plane_y = game->ray->old_plane_x * sin(-5*PI/180) + game->ray->plane_y * cos(-5*PI/180);
	mlx_clear_window(game->mlx, game->mlx_win);
}



