/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:55:18 by jogomes-          #+#    #+#             */
/*   Updated: 2023/03/28 14:11:18 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (0);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (0);
	ft_memcpy(str, s1, ft_strlen(s1));
	ft_memcpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	return (str);
}

/* #include <stdio.h>

int	main()
{
	char *s1 = "my favorite animal is";
    char *s2 = " ";
    char *s3 = "the nyancat";
    char *res = ft_strjoin(ft_strjoin(s1, s2), s3);

	printf("%s\n", res);
	return (0);
}
 */