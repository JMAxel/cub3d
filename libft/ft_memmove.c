/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:59:02 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/26 14:50:45 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*result;
	const char	*base;

	result = dest;
	base = src;
	if (!src && !dest && n > 0)
		return (0);
	if (result < base)
		while (n-- > 0)
			*result++ = *base++;
	else
	{
		result = dest + (n - 1);
		base = src + (n - 1);
		while (n-- > 0)
			*result-- = *base--;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main()
{
	char str[70] = "Isso e tudo pessoal";
	char str2[100] = "Prova";

	memmove(str + 6, str, 9);
	printf("Original: %s\n", str);
	
	char str3[70] = "Isso e tudo pessoal";
	char str4[100] = "Prova";

	ft_memmove(str3 + 6, str3, 9);
	printf("ft:       %s\n", str3);
	return (0);
} */