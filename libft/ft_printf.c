/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <jogomes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:22:03 by jogomes-          #+#    #+#             */
/*   Updated: 2022/10/05 16:46:38 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_letter(char *bf)
{
	int	bf_size;

	if (bf == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(bf, 1);
	bf_size = ft_strlen(bf);
	free(bf);
	return (bf_size);
}

static int	more_args(va_list args, const char *s, int p)
{
	char	*bf;
	int		bf_size;

	if (s[p] == 's')
		bf = ft_strdup(va_arg(args, char *));
	else if (s[p] == 'd' || s[p] == 'i')
		bf = ft_itoa(va_arg(args, int));
	else if (s[p] == 'u')
		bf = ft_itoa_pos(va_arg(args, unsigned int));
	else if (s[p] == 'x')
		bf = ft_itoa_hex(va_arg(args, unsigned int), "0123456789abcdef", 'x');
	else if (s[p] == 'X')
		bf = ft_itoa_hex(va_arg(args, unsigned int), "0123456789ABCDEF", 'X');
	else if (s[p] == 'p')
		bf = ft_itoa_hex(va_arg(args, unsigned long), "0123456789abcdef", 'p');
	else
		return (0);
	bf_size = count_letter(bf);
	return (bf_size - 1);
}

static int	find_args(const char *string, va_list args, int count)
{
	static int	position;
	int			check;

	position = 0;
	check = 0;
	while (string[position])
	{
		if (string[position] == '%')
		{
			position++;
			check++;
			if (string[position] == 'c')
				ft_putchar_fd(va_arg(args, int), 1);
			else if (string[position] == '%')
				ft_putchar_fd('%', 1);
			else
				count += more_args(args, string, position);
		}
		else
			ft_putchar_fd(string[position], 1);
		position++;
	}
	count += (position - check);
	return (count);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;

	va_start(args, string);
	count = 0;
	count = find_args(string, args, count);
	va_end(args);
	return (count);
}
