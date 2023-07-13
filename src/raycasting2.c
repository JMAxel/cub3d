#include "../include/cub3d.h"

void raycasting(t_game *game)
{

	camera(game);
}

void camera(t_game *game)
{
	int x;

	x = 0;
	while(x < w) //varrer todo o eixo x da camera;
	{
		game->ray->camera_x = 2 * x / (double)w -1; // coordenadas x no plano da camera;
		game->ray->r_dirx = game->ray->dir_x + game->ray->plane_x * game->ray->camera_x;
		game->ray->r_diry = game->ray->dir_y + game->ray->plane_y * game->ray->camera_x;
		DDA_set(game->ray); // mira o raio
		DDA_search(game); // atira o raio
		if(game->ray->side == 0) // vê onde na parede acertou;
			game->ray->perpwalldist = (game->ray->dist_xside - game->ray->delta_x);
		else
			game->ray->perpwalldist = (game->ray->dist_yside - game->ray->delta_y);
		//printf("distance %f\n",game->ray->perpwalldist);
		draw_wall(game, x);
		x++;
	}
}

void DDA_set(t_ray *ray)
{
	ray->mapx = (int)(ray->pos_x);//posição no grind
	ray->mapy = (int)(ray->pos_y);
	//se r_dirx ou r_diry for zero protegido.
	ray->delta_x = (ray->r_dirx == 0) ? 1e30 : fabs(1 / ray->r_dirx); //coeficinete angular da reta;
	ray->delta_y = (ray->r_diry == 0) ? 1e30 : fabs(1 / ray->r_diry);
	ray->hit = 0;
	set_side(ray); // determinar o sentido do raio
}

void set_side(t_ray *ray)
{
	if(ray->r_dirx < 0) //esquerda ou direita
    {
        ray->stepx = -1;
        ray->dist_xside = (ray->pos_x - ray->mapx) * ray->delta_x;
    }
    else
    {
     	ray->stepx = 1;
        ray->dist_xside = (ray->mapx + 1.0 - ray->pos_x) * ray->delta_x;
    }
    if(ray->r_diry < 0) // pra cima ou pra baixo
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

void DDA_search(t_game *game)
{
	while(game->ray->hit == 0)
	{
		if(game->ray->dist_xside < game->ray->dist_yside) //sempre da um passo para a direção do menor;
		{
			game->ray->dist_xside += game->ray->delta_x;
			game->ray->mapx += game->ray->stepx;
			game->ray->side = 0; 
		}
		else
		{
			game->ray->dist_yside += game->ray->delta_y;
			game->ray->mapy += game->ray->stepy;
			game->ray->side = 1; 
		}
		if(game->map->space[game->ray->mapx][game->ray->mapy] == '1')
			game->ray->hit = 1;
	}
	/*printf("[%c]",game->map->space[game->ray->mapx][game->ray->mapy]);
	printf("posição do raio[%d]::[%d] \n", game->ray->mapx, game->ray->mapy);
	printf("dist_side[%f]::[%f] \n", game->ray->dist_xside, game->ray->dist_yside)*/
}

void draw_wall(t_game *game, int x)
{
	int color = 0x005508;
	game->ray->lineheight = (int)(h / game->ray->perpwalldist);
	game->ray->drawstart = (- game->ray->lineheight + h) / 2;
    if(game->ray->drawstart < 0) 
		game->ray->drawstart = 0;
    game->ray->drawend = (game->ray->lineheight + h) / 2;
    if(game->ray->drawend >= h) 
		game->ray->drawend = h - 1;
	if(game->ray->side == 1)
		color = color / 2;
	putverline(game, color, x);
}

void putverline(t_game *game, int color, int x)
{
	int y = game->ray->drawstart;

	while(y < game->ray->drawend)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x, y, color);
		y++;
	}
}