#include "../include/cub3d.h"

void hit_wall(t_game *game)
{
	char c;
    game->ray->bi = (int) round(game->ray->py/64);
	game->ray->bj = (int) round(game->ray->px/64);
    c = game->map->space[game->ray->bi][game->ray->bj];
	if(c == '1')
		game->ray->hit = 1;
	else
		game->ray->hit = 0;
	printf("[%c] :: ",game->map->space[game->ray->bi][game->ray->bj]);
	printf("[%f][%f] :: ", game->ray->py, game->ray->px);
	printf("[%d][%d]\n", game->ray->bi, game->ray->bj);
}

void search_DDA(t_game *game)
{
	//se o coseno  for positivo aumenta pra direita; se não, aumenta para esquerda;
	if(cos(game->ray->d) >= 0)
		game->ray->px = game->ray->px + 64;
	else
		game->ray->px = game->ray->px - 64;
	//usando o angulo de inclinação conseguimos corelacionar py = px * tg(ray->d);
	if(game->ray->d != PI/2 && game->ray->d != 3*PI/2)
		game->ray->py = game->ray->pos_i + game->ray->px * tan(game->ray->d) ;
	hit_wall(game);
}

void set_DDA(t_game *game)
{
	//j matricial == x cardeziano; i matricial == y cardeziano invertido ( - y );
	game->ray->px = game->ray->pos_j + cos(game->ray->d) * 64;
	game->ray->py = game->ray->pos_i + sin(game->ray->d) * 64;
	//verificar se no grind aonde eu estou olhando é ou não parede;
	hit_wall(game);
	while(game->ray->hit == 0)
	{
		search_DDA(game);
	}
}

void walls_in_sight(t_game *game, double degree)
{
    game->ray->pos_i = (game->map->player_pos[0] - 0.5)*64;
	game->ray->pos_j = (game->map->player_pos[1] - 0.5)*64;
    printf("%i\n", game->map->player_pos[1]);
    game->ray->d = degree*(PI/180);
	set_DDA(game);
	game->ray->dist = sqrt((game->ray->px - game->ray->pos_j) * (game->ray->px - game->ray->pos_j) + (game->ray->py - game->ray->pos_i) * (game->ray->py - game->ray->pos_i));
	printf("dst :: [%f]\n", game->ray->dist);
    /*printf("[%d] :: ",game->map->space[game->ray->bi][game->ray->bj]);
	printf("[%f][%f] :: ", game->ray->py, game->ray->px);
	printf("[%d][%d]\n", game->ray->bi, game->ray->bj);*/
}