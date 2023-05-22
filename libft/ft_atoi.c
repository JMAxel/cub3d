/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:06:46 by jogomes-          #+#    #+#             */
/*   Updated: 2022/11/04 18:26:17 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_nbr(double nbr, int negative)
{
	int	result;

	nbr *= negative;
	if (nbr > 2147483647 || nbr < -2147483648)
		return (-2147483648);
	result = (int)nbr;
	return (result);
}

int	ft_atoi(const char *nptr)
{
	double	nbr;
	double	negative;

	nbr = 0;
	negative = 1;
	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\r' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
	{
		nptr++;
		negative = -1;
	}
	if (*nptr == '+')
	{
		if (negative == -1)
			return (0);
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		nbr = (nbr * 10) + (*nptr - '0');
		nptr++;
	}
	return (check_nbr(nbr, negative));
}

/* #include <stdio.h>

int	main()
{
	char str[100] = "\n\n\n  -46\b9 \n5d6";
	
	printf("Original: %d\n", atoi(str));
	printf("ft: %d\n", ft_atoi(str));
	return (0);
} */