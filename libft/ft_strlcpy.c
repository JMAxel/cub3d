/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:28:13 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/17 15:15:56 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < size)
		ft_memcpy(dest, src, srclen + 1);
	else if (size != '\0')
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen);
}

/* #include <stdio.h>
#include <string.h>

int	main()
{
	char str[100] = "Teste Final";
	char dest[100] = "Proof";
	int i;
	
	i = strlcpy(dest, str, 5);
	printf("Original: %s / Tamanho: %d\n", dest, i);

	char dest2[100] = "Proof";
	char str2[100] = "Teste Final";
	
	i = ft_strlcpy(dest2, str2, 5);
	printf("ft: %s / Tamanho: %d\n", dest, i);
	return 0;
} */