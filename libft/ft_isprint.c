/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:35:24 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/05 11:51:11 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
	char c;

	c = 126;
	printf("Original: %d", isprint(c));
	printf("\n");
	printf("ft: %d", ft_isprint(c));
	printf("\n");
	return 0;
} */