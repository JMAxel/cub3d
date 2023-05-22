/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:45:29 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/05 11:51:04 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
	char c;

	c = '8';
	printf("Original: %d", isdigit(c));
	printf("\n");
	printf("ft: %d", ft_isdigit(c));
	printf("\n");
	return 0;
} */