/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 10:49:20 by jogomes-          #+#    #+#             */
/*   Updated: 2022/06/06 13:16:27 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*strup;
	unsigned int	i;

	i = ft_strlen(s);
	strup = ft_calloc(i + 1, sizeof(char));
	if (!strup)
		return (0);
	ft_memcpy(strup, s, i);
	return (strup);
}

/* #include <stdio.h>
#include <string.h>

int	main()
{
	char *str = "this is a normal test";
	char *str2 = "this is a normal test";

	printf("Original: %s / first: %d\n", strdup(str), ft_strlen(str));
	printf("ft:       %s / first: %d\n", ft_strdup(str2), ft_strlen(str2));
	return (0);
} */