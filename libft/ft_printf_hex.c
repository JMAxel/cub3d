/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:01:27 by jogomes-          #+#    #+#             */
/*   Updated: 2022/10/05 16:46:34 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_prefix(char *result)
{
	int		position;
	int		count;
	char	*new_result;

	position = 2;
	count = ft_strlen(result);
	new_result = ft_calloc(count + 2, sizeof(char));
	new_result[0] = '0';
	new_result[1] = 'x';
	while (count > 0)
	{
		new_result[position] = result[position - 2];
		position++;
		count--;
	}
	free(result);
	return (new_result);
}

static long	ft_count_itoa_hex(unsigned long n)
{
	unsigned long	count;

	count = 0;
	while (n > 15)
	{
		count++;
		n = n / 16;
	}
	return (count + 1);
}

static long	ft_pow_atoa_hex(unsigned long i)
{
	long	pow;

	pow = 1;
	while (--i > 0)
		pow *= 16;
	return (pow);
}

char	*ft_itoa_hex(unsigned long nbr, char *base, char letter)
{
	long				count;
	long				start;
	char				*result;

	count = ft_count_itoa_hex(nbr);
	result = ft_calloc(count + 2, sizeof(char));
	start = 0;
	if (result)
	{
		while (count > 0)
		{
			result[start] = base[(nbr / ft_pow_atoa_hex(count))];
			nbr -= (nbr / ft_pow_atoa_hex(count)) * ft_pow_atoa_hex(count);
			start++;
			count--;
		}
	}
	if (letter == 'p')
		result = ft_prefix(result);
	return (result);
}
