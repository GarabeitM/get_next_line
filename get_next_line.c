/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 15:56:11 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/19 16:24:16 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_to_remainder(int fd, char *buffer, char *remainder)
{
	ssize_t		bytes_read;
	char		*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(remainder);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!remainder)
			remainder = ft_strdup("");
		tmp = remainder;
		remainder = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remainder);
}

static char	*ft_get_line(char *remainder)
{
	size_t		i;
	char		*printed_line;

	i = 0;
	if (remainder[i] == '\0')
		return (NULL);
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	printed_line = ft_substr(remainder, 0, i + 1);
	if (*printed_line == '\0')
	{
		free(printed_line);
		printed_line = NULL;
	}
	return (printed_line);
}

static char	*ft_clean(char *remainder)
{
	size_t		i;
	char		*remaining_str;

	i = 0;
	if (remainder[i] == '\0')
		return (NULL);
	while (remainder[i] != '\n' && remainder[i] != '\0')
		i++;
	remaining_str = ft_substr(remainder, i + 1, ft_strlen(remainder) - i);
	if (*remaining_str == '\0')
	{
		free(remaining_str);
		remaining_str = NULL;
	}
	free(remainder);
	remainder = NULL;
	return (remaining_str);
}

char	*get_next_line(int fd)
{
	char		*printed_line;
	char		*buffer;
	static char	*remainder;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (remainder);
		remainder = NULL;
		free (buffer);
		buffer = NULL;
		return (NULL);
	}
	remainder = ft_read_to_remainder(fd, buffer, remainder);
	free(buffer);
	buffer = NULL;
	if (!remainder)
		return (NULL);
	printed_line = ft_get_line(remainder);
	remainder = ft_clean(remainder);
	return (printed_line);
}
