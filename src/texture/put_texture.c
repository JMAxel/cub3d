#include "../../include/cub3d.h"

void	prepare_draw(t_game *game, t_ray *ray, t_info *info)
{
	ray->lineheight = (int)(H / ray->walldist);
	ray->drawstart = (- ray->lineheight + H) / 2;
    if(ray->drawstart < 0) 
		ray->drawstart = 0;
    ray->drawend = (ray->lineheight + H) / 2;
    if(ray->drawend >= H) 
		ray->drawend = H - 1;
    info->tex = game->map->space[ray->mapx][ray->mapy];
    if (ray->side == 0)
		info->wall_x = ray->pos_y + ray->walldist * ray->r_diry;
	else
		info->wall_x = ray->pos_x + ray->walldist * ray->r_dirx;
    info->wall_x -= floor(info->wall_x);
    info->tex_x = (int)(info->wall_x * (double)TEXSIZE);
    if (ray->side == 0 && ray->r_dirx > 0)
		info->tex_x = TEXSIZE - info->tex_x - 1;
	if (ray->side == 1 && ray->r_diry < 0)
		info->tex_x = TEXSIZE - info->tex_x - 1;
    info->step = 1.0 * TEXSIZE / ray->lineheight;
	info->tex_p = (ray->drawstart - H / 2 + ray->lineheight / 2)
		* info->step;
}

void	draw_wall(t_ray *ray, t_info *info, int x)
{
	int	i;

	i = ray->drawstart;
	while (i < ray->drawend)
	{
		info->tex_y = (int)info->tex_p & (TEXSIZE - 1);
		info->tex_p += info->step;
		info->color = check_texture(info, ray);
		if (ray->side == 1)
			info->color = (info->color >> 1) & 8355711;
		info->buf[i][x] = info->color;
		info->check_buf = 1;
		i++;
	}
}

void	floor_calc(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			info->color = info->f_color;
			info->color = (info->color >> 1) & 8355711;
			info->buf[i][j] = info->color;
			info->color = info->c_color;
			info->color = (info->color >> 1) & 8355711;
			info->buf[H - i - 1][j] = info->color;
			j++;
		}
		i++;
	}
}

void	update_visual(t_game *game, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			info->data[i * W + j] = info->buf[i][j];
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, info->img, 0, 0);
}
