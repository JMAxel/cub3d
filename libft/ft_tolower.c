/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:28:54 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/05 15:32:02 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>

int main()
{
	printf("Original: %c\n", tolower('c'));
	printf("ft: %c\n", ft_tolower('c'));
	return (0);
} */