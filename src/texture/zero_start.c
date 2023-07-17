#include "../../include/cub3d.h"

void	start_tex_buf(t_info *info)
{
	int	i;

	i = 0;
	info->texture = ft_calloc(4, sizeof(int *));
	while (i < 4)
	{
		info->texture[i] = ft_calloc(TEXSIZE * TEXSIZE, sizeof(int));
		i++;
	}
	i = 0;
	info->buf = ft_calloc(H, sizeof(int *));
	while (i < W)
	{
		info->buf[i] = ft_calloc(W, sizeof(int));
		i++;
	}
}

void	zero_buf(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
			info->buf[i][j++] = 0;
		i++;
	}
}

void	zero_start(t_game *game)
{
	int	i;
	int	j;

	start_tex_buf(game->info);
	zero_buf(game->info);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < TEXSIZE * TEXSIZE)
			game->info->texture[i][j++] = 0;
		i++;
	}
	game->info->check_buf = 0;
    game->info->t_height = 100;
    game->info->t_width = 100;
}