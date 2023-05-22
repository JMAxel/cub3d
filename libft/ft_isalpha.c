/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:22:30 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/05 11:50:55 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 96 && c < 123) || (c > 64 && c < 91))
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
    char c;

    c = 'Z';
	printf("Original: %d", isalpha(c));
	printf("\n");
    printf("ft: %d", ft_isalpha(c));
	printf("\n");
    return 0;
} */