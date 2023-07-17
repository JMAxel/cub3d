#include "../../include/cub3d.h"

int raycasting(t_game *game)
{
	if (game->info->w == 1)
		up_key(game);
	else if (game->info->s == 1)
		down_key(game);
	else if (game->info->d == 1)
		right_key(game);
	else if (game->info->a == 1)
		left_key(game);
	floor_calc(game->info);
	camera(game, game->ray);
	update_visual(game, game->info);
	return (0);
}

void camera(t_game *game, t_ray *ray)
{
	int x;

	x = 0;
	while(x < W)
	{
		ray->camera_x = 2 * x / (double)W -1;
		ray->r_dirx = ray->dir_x + ray->plane_x * ray->camera_x;
		ray->r_diry = ray->dir_y + ray->plane_y * ray->camera_x;
		DDA_set(game->ray);
		DDA_search(game, game->ray);
		prepare_draw(game, ray, game->info);
		draw_wall(ray, game->info, x);
		x++;
	}
}

void DDA_set(t_ray *ray)
{
	ray->mapx = (int)(ray->pos_x);
	ray->mapy = (int)(ray->pos_y);
	ray->delta_x = (ray->r_dirx == 0) ? 1e30 : fabs(1 / ray->r_dirx);
	ray->delta_y = (ray->r_diry == 0) ? 1e30 : fabs(1 / ray->r_diry);
	ray->hit = 0;
	set_side(ray);
}

void set_side(t_ray *ray)
{
	if(ray->r_dirx < 0)
    {
        ray->stepx = -1;
        ray->dist_xside = (ray->pos_x - ray->mapx) * ray->delta_x;
    }
    else
    {
     	ray->stepx = 1;
        ray->dist_xside = (ray->mapx + 1.0 - ray->pos_x) * ray->delta_x;
    }
    if(ray->r_diry < 0)
    {
    	ray->stepy = -1;
        ray->dist_yside = (ray->pos_y - ray->mapy) * ray->delta_y;
    }
    else
    {
    	ray->stepy = 1;
        ray->dist_yside = (ray->mapy + 1.0 - ray->pos_y) * ray->delta_y;
    }
}

void DDA_search(t_game *game, t_ray *ray)
{
	while(ray->hit == 0)
	{
		if(ray->dist_xside < ray->dist_yside)
		{
			ray->dist_xside += ray->delta_x;
			ray->mapx += ray->stepx;
			ray->side = 0; 
		}
		else
		{
			ray->dist_yside += ray->delta_y;
			ray->mapy += ray->stepy;
			ray->side = 1; 
		}
		if(game->map->space[ray->mapx][ray->mapy] == '1')
			game->ray->hit = 1;
	}
	if(ray->side == 0)
		ray->walldist = (ray->dist_xside - ray->delta_x);
	else
		ray->walldist = (ray->dist_yside - ray->delta_y);
}