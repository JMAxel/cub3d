/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:14:15 by jogomes-          #+#    #+#             */
/*   Updated: 2023/01/05 17:00:23 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	*ptr;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/* #include <stdio.h>

int	main()
{
	int	*ptr;
	int *ptr2;
	int i;
	
	ptr = calloc(0, sizeof(int));
	i = 0;
	printf("Original: ");
	while (i++ < 10)
		printf("%d  ", *ptr);
	printf("\n");
	ptr2 = ft_calloc(0, sizeof(int));
	i = 0;
	printf("ft:       ");
	while (i++ < 10)
		printf("%d  ", *ptr2);
	printf("\n");
	return (0);
} */