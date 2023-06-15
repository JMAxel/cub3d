/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:19 by jogomes-          #+#    #+#             */
/*   Updated: 2023/06/14 23:47:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_map(t_map *map)
{
	free(map->no_tex);
	free(map->so_tex);
	free(map->we_tex);
	free(map->ea_tex);
	free_matrix(map->space);
	free(map);
}

int	main(int argc, char *argv[])
{
	t_map	*map;
	int		i;

	i = 0;
	if (argc != 2)
		err_msg("Invalid amount of arguments.\nUsage: ./cub3d example.cub\n");
	map = (t_map *)malloc(sizeof(t_map));
	check_map(map, argv[1]);
	printf("%s\n", map->no_tex);
	printf("%s\n", map->so_tex);
	printf("%s\n", map->we_tex);
	printf("%s\n", map->ea_tex);
	printf("%d %d %d\n", map->f_color[0], map->f_color[1], map->f_color[2]);
	printf("%d %d %d\n\n", map->c_color[0], map->c_color[1], map->c_color[2]);
	while (map->space[i])
	{
		printf("%s\n", map->space[i]);
		i++;
	}
	printf("It works!\n");
	free_map(map);
	return (0);
}
