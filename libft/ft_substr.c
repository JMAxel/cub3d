/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:23:47 by jogomes-          #+#    #+#             */
/*   Updated: 2022/06/06 16:19:51 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*strup;
	size_t	true_len;

	if (!s)
		return (0);
	true_len = ft_strlen(s);
	if (len > true_len)
		len = true_len;
	strup = ft_calloc(len + 1, sizeof(char));
	if (!strup || start > ft_strlen(s))
		return (strup);
	ft_memcpy(strup, s + start, len);
	return (strup);
}

/* #include <stdio.h>

int	main()
{
	char *str = "01234";
	char *ret = ft_substr(str, 10, 10);

	printf("%d\n", ft_strncmp(ret, "", 1));
	return (0);
} */