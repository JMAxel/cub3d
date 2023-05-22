/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:56:00 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/19 17:20:58 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*point;
	const char	*hold;

	if (c == '\0')
		return (ft_strchr(s, '\0'));
	point = ft_strchr(s, c);
	if (!point)
		hold = NULL;
	while (point != 0)
	{
		hold = point;
		s = point + 1;
		point = ft_strchr(s, c);
	}
	return ((char *)hold);
}

/* #include <stdio.h>
#include <string.h>

int main()
{
	char		str2[] = "bonjour";
	
	printf("Original: %s\n", strrchr(str2 + 2, 'b'));
	printf("ft: %s\n", ft_strrchr(str2 + 2, 'b'));
	return (0);
} */