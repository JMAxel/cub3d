/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 10:59:43 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/05 11:50:50 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 96 && c < 123) || (c > 64 && c < 91) || (c > 47 && c < 58))
		return (1);
	else
		return (0);
}

/* #include <stdio.h>
#include <ctype.h>
int main()
{
    char c;

    c = '+';
	printf("Original: %d", isalnum(c));
	printf("\n");
    printf("ft: %d", ft_isalnum(c));
	printf("\n");
    return 0;
} */