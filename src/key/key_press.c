#include "../../include/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == 65307)
		end_game(game);
	else if (key == 119)
        game->ray->w = 1;
	else if (key == 115)
        game->ray->s = 1;
	else if(key == 97)
        game->ray->a = 1;
	else if(key == 100)
        game->ray->d = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == 119)
        game->ray->w = 0;
	else if (key == 115)
        game->ray->s = 0;
	else if(key == 97)
        game->ray->a = 0;
	else if(key == 100)
        game->ray->d = 0;
	return (0);
}