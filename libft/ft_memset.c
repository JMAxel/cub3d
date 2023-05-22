/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:04:15 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/09 11:34:35 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = c;
	return (s);
}

/* #include <stdio.h>
#include <string.h>

int	main()
{
	char str[20] = "Isso é tudo pessoal";

	memset(str, '.', 18);
	printf("Original: %s\n", str);
	ft_memset(str, '$', 18);
	printf("ft: %s\n", str);
	return (0);
} */