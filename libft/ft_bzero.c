/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:24:39 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/11 15:07:58 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n-- > 0)
		*ptr++ = '\0';
}

/* #include <stdio.h>
#include <string.h>

int	main()
{
	char str[13] = "Hello World!";

	bzero(str, 5);
	printf("Original: %s\n", str);

	char str2[13] = "Hello World!";
	
	ft_bzero(str2, 5);
	printf("ft: %s\n", str2);
	return(0);
} */