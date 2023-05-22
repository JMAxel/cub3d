/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:34:31 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/31 14:19:33 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static void		iter(unsigned int i, char *c)
{
	static int indexArray[11] = {0};

	if (i > 10 || indexArray[i] == 1)
		write(1, "wrong index\n", 12);
	else
		indexArray[i] = 1;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
	else if (*c >= 'A' && *c <= 'Z')
		*c = *c + 32;
} */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/* #include <string.h>
#include <stdio.h>

int	main()
{
	char *str = (char *)malloc(sizeof(*str) * 12);
	
	strcpy(str, "LoReM iPsUm");
	ft_striteri(str, &iter);
	
	printf("%s\n", str);
	return (0);
} */