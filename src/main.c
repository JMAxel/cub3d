/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:35:19 by jogomes-          #+#    #+#             */
/*   Updated: 2023/05/22 16:49:18 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char *argv[])
{
	t_map	*map;

	if (argc != 2)
		err_msg("Invalid amount of arguments.\nUsage: ./cub3d example.cub\n");
	map = (t_map *)malloc(sizeof(t_map));
	check_map(map, argv[1]);
	printf("It works!\n");
	return (0);
}
