/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:40:19 by jogomes-          #+#    #+#             */
/*   Updated: 2022/11/04 19:34:45 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_create_words(char const *s, char c, char **matriz, int word)
{
	size_t	init;
	size_t	end;

	init = 0;
	end = 0;
	while (s[init])
	{
		if (s[init] != c)
		{
			while (s[init + end] != c && s[init + end] != '\0')
				end++;
			matriz[word] = ft_substr(s, init, end);
			init += end;
			word++;
			end = 0;
		}
		else
			init++;
	}
}

int	ft_alloc_space(char const *s, char c)
{
	int	spaces;
	int	letter;

	spaces = 0;
	letter = 0;
	while (s[letter])
	{
		if (s[letter] != c)
		{
			while (s[letter] != c && letter < (int)ft_strlen(s))
				letter++;
			spaces++;
		}
		else
			letter++;
	}
	return (spaces);
}

char	**ft_split(char const *s, char c)
{
	char	**matriz;
	int		word;
	int		count;

	word = 0;
	if (!s)
		return (0);
	count = ft_alloc_space(s, c);
	matriz = ft_calloc((count) + 1, sizeof(char *));
	if (!matriz)
		return (0);
	ft_create_words(s, c, matriz, word);
	return (matriz);
}

/* #include <stdio.h>

int main()
{
	char **matriz;
	char * splitme = strdup("Tr  ipouille");
	
	matriz = ft_split(splitme, ' ');
	
	while (*matriz)
	{
		printf("%s\n", *matriz);
		matriz++;
	}
	printf("NULO: %s\n", *matriz);

	return (0);
} */