/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:50:47 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/06 13:56:09 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/* #include <stdio.h>
#include <string.h>
int main()
{
	char *s;

	s = "Isso é tudo pessoal";
	printf("Original: %lu\n", strlen(s));
	printf("ft: %lu\n", ft_strlen(s));
	return (0);
} */