/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:12:49 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/05 11:51:00 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
	char c;

	c = '\n';
	printf("Original: %d\n", isascii(c));
	printf("ft: %d\n", ft_isascii(c));
	
	return (0);
} */