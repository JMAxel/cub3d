/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_calc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 18:23:26 by jogomes-          #+#    #+#             */
/*   Updated: 2023/07/15 18:23:26 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void    floor_calc(t_info *info, t_time *time)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            time->color = info->f_color;
            time->color = (time->color >> 1) & 8355711;
            info->buf[i][j] = time->color;
            time->color = info->c_color;
            time->color = (time->color >> 1) & 8355711;
            info->buf[height - i - 1][j] = time->color;
            j++;
        }
        i++;
    }
}