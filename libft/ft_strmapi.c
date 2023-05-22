/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:54:34 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/27 14:45:27 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* static char	ft_check_tolower(unsigned int i, char c)
{
	if (ft_isalpha(c))
		if (c > 64 && c < 91)
			c += 32;
	i++;
	return (c);
}

static char	ft_check_toupper(unsigned int i, char c)
{
	if (ft_isalpha(c))
		if (c > 96 && c < 123)
			c -= 32;
	i++;
	return (c);
} */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	i = 0;
	if (!s)
		return (0);
	result = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (result)
	{
		while (s[i] != '\0')
		{
			result[i] = (*f)(i, s[i]);
			i++;
		}	
	}
	return (result);
}

/* #include <stdio.h>

int	main()
{
	char test[100] = "TesTaNdo";

	printf("%s\n", ft_strmapi(test, ft_check_toupper));
	printf("%s\n", ft_strmapi(test, ft_check_tolower));
	return (0);
} */