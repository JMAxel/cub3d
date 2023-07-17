#include "../../include/cub3d.h"

void	load_image(t_game *game, t_info *info, int *texture, char *path)
{
	int	x;
	int	y;

	x = 0;
    
    info->img = mlx_xpm_file_to_image(game->mlx, path, &info->t_width,
			&info->t_height);
	info->data = (int *)mlx_get_data_addr(info->img, &info->bpp,
			&info->size_l, &info->endian);
   
	while (x < info->t_height)
	{
		y = 0;
		while (y < info->t_width)
		{
			texture[info->t_width * x + y] = info->data[info->t_width * x + y];
			y++;
		}
		x++;
	}
	mlx_destroy_image(game->mlx, info->img);
}

void	load_texture(t_game *game)
{
    load_image(game, game->info, game->info->texture[0], game->map->no_tex);
	load_image(game, game->info, game->info->texture[1], game->map->so_tex);
	load_image(game, game->info, game->info->texture[2], game->map->ea_tex);
	load_image(game, game->info, game->info->texture[3], game->map->we_tex);
}

int	check_texture(t_info *info, t_ray *ray)
{
	if (ray->r_dirx < 0 && ray->side == 0)
		return (info->texture[0][TEXSIZE * info->tex_y + info->tex_x]);
	if (ray->r_dirx >= 0 && ray->side == 0)
		return (info->texture[1][TEXSIZE * info->tex_y + info->tex_x]);
	if (ray->r_diry < 0 && ray->side == 1)
		return (info->texture[2][TEXSIZE * info->tex_y + info->tex_x]);
	if (ray->r_diry > 0 && ray->side == 1)
		return (info->texture[3][TEXSIZE * info->tex_y + info->tex_x]);
	return (0);
}

void	creating_game(t_game *game, t_info *info)
{
    load_texture(game);
	game->mlx_win = mlx_new_window(game->mlx, W, H, "cub3d");
	info->img = mlx_new_image(game->mlx, W, H);
	game->info->data = (int *)mlx_get_data_addr(info->img, &info->bpp,
			&info->size_l, &info->endian);
}