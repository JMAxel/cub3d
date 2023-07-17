#include "../../include/cub3d.h"

int	key_press(int key, t_game *game)
{
	if (key == 65307)
		end_game(game);
	else if (key == 119)
        game->info->w = 1;
	else if (key == 115)
        game->info->s = 1;
	else if(key == 97)
        game->info->a = 1;
	else if(key == 100)
        game->info->d = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == 119)
        game->info->w = 0;
	else if (key == 115)
        game->info->s = 0;
	else if(key == 97)
        game->info->a = 0;
	else if(key == 100)
        game->info->d = 0;
	return (0);
}