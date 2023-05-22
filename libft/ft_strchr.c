/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:35:26 by jogomes-          #+#    #+#             */
/*   Updated: 2022/11/05 14:00:19 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	letter;

	letter = (char) c;
	if (letter == '\0')
	{
		while (*s != '\0')
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == letter)
			return ((char *)s);
		s++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char s[100] = "tripouille";
	
	printf("Original: %s\n", strchr(s, 't' + 256));
	printf("ft: %s\n", ft_strchr(s, 't' + 256));
	return (0);
} */