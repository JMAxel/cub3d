/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 12:47:25 by jogomes-          #+#    #+#             */
/*   Updated: 2022/06/08 13:22:20 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	srclen;
	unsigned int	destlen;

	srclen = ft_strlen(src);
	destlen = 0;
	while (destlen < size)
	{
		if (dest[destlen] == '\0')
			break ;
		destlen++;
	}
	if (destlen == size)
		return (srclen + size);
	if (srclen < (size - destlen))
		ft_memcpy(dest + destlen, src, srclen + 1);
	else
	{
		ft_memcpy(dest + destlen, src, (size - destlen - 1));
		dest[destlen + size - 1] = '\0';
	}
	return (destlen + srclen);
}

/* #include <stdio.h>
#include <string.h>

int	main()
{
	char dest[14] = "a";
	int i;

	i = strlcat(dest, "lorem ipsum dolor sit amet", 15);
	printf("Original: %s / Tamanho: %d\n", dest, i);

	char dest2[14] = "a";
	int j;

	j = ft_strlcat(dest2, "lorem ipsum dolor sit amet", 15);
	printf("ft: %s / Tamanho: %d\n", dest2, j);
	return (0);
} */