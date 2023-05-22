/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 11:01:17 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/27 14:39:31 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_pow_atoa(int i)
{
	int	pow;

	pow = 1;
	while (--i > 0)
		pow *= 10;
	return (pow);
}

static int	ft_count_itoa(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
		count++;
	while (n > 9 || n < -9)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				count;
	int				start;
	char			*result;
	unsigned int	negative;

	negative = n;
	count = ft_count_itoa(n) + 1;
	result = ft_calloc(count + 1, sizeof(char));
	start = 0;
	if (result)
	{
		if (n < 0)
		{
			result[start++] = '-';
			negative = n * -1;
			count--;
		}
		while (count > 0)
		{
			result[start++] = (negative / ft_pow_atoa(count)) + '0';
			negative -= (negative / ft_pow_atoa(count)) * ft_pow_atoa(count);
			count--;
		}
	}
	return (result);
}

/* #include <stdio.h>

int	main()
{
	printf("%s\n", ft_itoa(-5859));
	return (0);
} */