/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:02:39 by jogomes-          #+#    #+#             */
/*   Updated: 2023/01/05 17:00:10 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*result;
	char		*base;
	int			count;

	result = dest;
	base = (char *)src;
	count = 0;
	if (!src && !dest && n > 0)
		return (0);
	while (n-- > 0)
	{
		result[count] = base[count];
		count++;
	}
	return (result);
}

/* #include <string.h>
#include <stdio.h>

int main()
{
    void	*mem;
	
	mem = malloc(sizeof(*mem) * 30);
    printf("Original: %s\n", memcpy(((void *)0), ((void *)0), 3));
    printf("ft:       %s\n", ft_memcpy(((void *)0), ((void *)0), 3));
    return 0;
} */