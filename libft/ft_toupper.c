/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:15:40 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/05 15:24:09 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}

/* #include <stdio.h>
#include <ctype.h>

int main()
{
	printf("Original: %c\n", toupper('c'));
	printf("ft: %c\n", ft_toupper('c'));
	return (0);
} */