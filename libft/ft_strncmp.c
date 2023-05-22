/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:05:58 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/27 10:56:04 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- != 0 && (*ptr1 != '\0' || *ptr2 != '\0'))
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
	char *s1 = "the cake is a lie !\0I'm hidden lol\r\n";
    char *s2 = "there is no stars in the sky";
    size_t size = strlen("the cake is a lie !\0I'm hidden lol\r\n");
    int i1 = ((strncmp(s1, s2, size) > 0) ? 1 : 
	((strncmp(s1, s2, size) < 0) ? -1 : 0));
    int i2 = ((ft_strncmp(s1, s2, size) > 0) ? 1 : 
	((ft_strncmp(s1, s2, size) < 0) ? -1 : 0));
	
	printf("Original: %d\n", i1);
	printf("ft:       %d\n", i2);
	return (0);
} */