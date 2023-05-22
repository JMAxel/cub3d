/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jogomes- <leugim3005@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 13:02:57 by jogomes-          #+#    #+#             */
/*   Updated: 2023/03/28 14:09:44 by jogomes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*erase_line(char *buffer)
{
	char	*new_buffer;
	int		count_buffer;
	int		count_new;

	count_buffer = 0;
	while (buffer[count_buffer] && buffer[count_buffer] != '\n')
		count_buffer++;
	if (!buffer[count_buffer] || !buffer[count_buffer + 1])
	{
		free(buffer);
		return (NULL);
	}
	new_buffer = ft_calloc((ft_strlen(buffer) - count_buffer) + 1, 1);
	count_buffer++;
	count_new = 0;
	while (buffer[count_buffer])
		new_buffer[count_new++] = buffer[count_buffer++];
	free(buffer);
	return (new_buffer);
}

static char	*create_line(char *buffer)
{
	char	*answer;
	int		count;

	count = 0;
	while (buffer[count] != '\0' && buffer[count] != '\n')
		count++;
	if (buffer[count] == '\n')
		count++;
	answer = ft_calloc(count + 1, sizeof(char));
	if (!answer)
		return (NULL);
	count = 0;
	while (buffer[count] && buffer[count] != '\n')
	{
		answer[count] = buffer[count];
		count++;
	}
	answer[count] = buffer[count];
	return (answer);
}

static char	*read_fd(int fd, char *buffer, int buffer_size)
{
	int		bytes;
	char	*text;

	bytes = 1;
	while (bytes > 0)
	{
		text = ft_calloc(buffer_size + 1, sizeof(char));
		bytes = read(fd, text, buffer_size);
		if (bytes <= 0)
			break ;
		if (!buffer)
		{
			buffer = ft_calloc(buffer_size + 1, sizeof(char));
			buffer = ft_memcpy(buffer, text, buffer_size);
			free(text);
		}
		else
			buffer = ft_strjoin_free(buffer, text);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bytes <= 0)
		free(text);
	return (buffer);
}

char	*get_next_line(int fd, int buffer_size)
{
	static char	*buffer;
	char		*answer;

	if (fd < 0 || buffer_size <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (buffer)
	{
		if (!ft_strchr(buffer, '\n'))
			buffer = read_fd(fd, buffer, buffer_size);
	}
	else
		buffer = read_fd(fd, buffer, buffer_size);
	if (!buffer || buffer[0] == 0)
		return (NULL);
	answer = create_line(buffer);
	buffer = erase_line(buffer);
	return (answer);
}
