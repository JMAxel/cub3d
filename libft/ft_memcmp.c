/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:01:33 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/26 15:20:47 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*ptr1;
	unsigned const char	*ptr2;

	ptr1 = s1;
	ptr2 = s2;
	if (n == 0)
		return (0);
	while (n-- != 0)
	{
		if (*ptr1 > *ptr2 || *ptr1 < *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int	main()
{
	char *s1 = "\0atoms\0\0\0\0";
    char *s2 = "atoms\0abc";
    size_t size = 8;
    int i1 = memcmp(s1, s2, size);
    int i2 = ft_memcmp(s1, s2, size);

    printf("Original: %d\n", i1);
	printf("ft:       %d\n", i2);

	return (0);
} */