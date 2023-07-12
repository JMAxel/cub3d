/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 20:44:59 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/07 20:44:59 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    load_image(t_game *game, t_info *info, int *texture, char *path)
{
    int x;
    int y;

    x = 0;
    info->img = mlx_xpm_file_to_image(game->mlx, path, texSize, texSize);
    img->data = (int *)mlx_get_data_addr(info->img, info->bpp, info->line,
            info->endian);
    while (x < texSize)
    {
        y = 0;
        while (y < texSize)
        {
            texture[texSize * y + x] = info->data[texSize * y + x];
            y++;
        }
        x++;
    }
    mlx_destroy_image(game->mlx, info->img);
}

void    load_texture(t_game *game)
{
    load_image(game, game->info, game->info->texture[0], game->map->no_tex);
    load_image(game, game->info, game->info->texture[1], game->map->so_tex);
    load_image(game, game->info, game->info->texture[2], game->map->we_tex);
    load_image(game, game->info, game->info->texture[3], game->map->ea_tex);
}

void    creating_game(t_game *game)
{
    load_textures(game);
    game->mlx_win = mlx_new_window(game->mlx, width, height, "cub3d");
    game->mlx_img = mlx_new_image(game->mlx, width, height);
}