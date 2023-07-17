#include "../../include/cub3d.h"

void init_ray(t_game *game)
{
    game->ray->pos_x = game->map->player_pos[0];
	game->ray->pos_y = game->map->player_pos[1];
	game->ray->dir_x = -1;
	game->ray->dir_y = 0;
	game->ray->plane_x = 0;
	game->ray->plane_y = 0.66;
}