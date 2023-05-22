/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:15:30 by jogomes-          #+#    #+#             */
/*   Updated: 2022/05/31 15:25:44 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_end(int end, int begin, char const *s1, char const *set)
{
	int	count;

	count = 0;
	while (set[count] != '\0' && begin < end)
	{
		if (s1[end] == set[count])
		{
			count = -1;
			end--;
		}
		count++;
	}
	return (end);
}

static int	ft_count_begin(int begin, char const *s1, char const *set)
{
	int	count;

	count = 0;
	while (set[count] != '\0')
	{
		if (s1[begin] == set[count])
		{
			begin++;
			count = -1;
		}
		count++;
	}
	return (begin);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			begin;
	int			end;

	if (!s1)
		return (0);
	begin = 0;
	end = ft_strlen(s1) - 1;
	begin = ft_count_begin(begin, s1, set);
	end = ft_count_end(end, begin, s1, set);
	return (ft_substr(s1, begin, (end - begin) + 1));
}

/* #include <stdio.h>

int	main()
{
	char str[100] = "lorem ipsum dolor sit amet \n \t ";

	printf("%s\n", ft_strtrim(str, "\t \n"));
	return (0);
} */