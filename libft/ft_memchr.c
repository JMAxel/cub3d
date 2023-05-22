/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:40:44 by jogomes-          #+#    #+#             */
/*   Updated: 2022/06/01 13:52:30 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*ptr;

	ptr = s;
	while (n-- != 0)
	{
		if (*ptr == (unsigned char)c)
			return ((char *)ptr);
		ptr++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	
	printf("Original: %s\n", (char *)memchr(tab, -1, 7));
	printf("ft: %s\n", (char *)ft_memchr(tab, -1, 7));
	return (0);
} */