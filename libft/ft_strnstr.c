/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:15:26 by jogomes-          #+#    #+#             */
/*   Updated: 2022/06/06 13:30:48 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	haystack;
	size_t	needle;

	if (!*little)
		return ((char *)big);
	haystack = 0;
	while (haystack < len)
	{
		needle = 0;
		while (big[haystack] == little[needle])
		{
			haystack++;
			needle++;
			if (little[needle] == '\0')
				return ((char *)big + (haystack - needle));
			if (big[haystack] != little[needle] || haystack == len)
				break ;
		}
		if (big[haystack] != little[needle])
			haystack -= needle;
		if (big[haystack] == '\0' || haystack == len)
			return (0);
		haystack++;
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>

int	main()
{
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	
	printf("Original: %s\n", strnstr(haystack, needle, 5));
	printf("ft: %s\n", ft_strnstr(haystack, needle, 5));
	return (0);
} */