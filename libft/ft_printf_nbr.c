/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 13:44:43 by jogomes-          #+#    #+#             */
/*   Updated: 2022/10/05 16:46:28 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_pow_atoa(long i)
{
	long	pow;

	pow = 1;
	while (--i > 0)
		pow *= 10;
	return (pow);
}

static long	ft_count_itoa_pos(long n)
{
	long	count;

	count = 0;
	while (n > 9 || n < -9)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa_pos(long nbr)
{
	long				count;
	long				start;
	char				*result;

	if (nbr >= 4294967295)
		nbr = 4294967295;
	count = ft_count_itoa_pos(nbr) + 1;
	result = ft_calloc(count + 1, sizeof(char));
	start = 0;
	if (result)
	{
		while (count > 0)
		{
			result[start] = (nbr / ft_pow_atoa(count)) + '0';
			nbr -= (nbr / ft_pow_atoa(count)) * ft_pow_atoa(count);
			start++;
			count--;
		}
	}
	return (result);
}
