/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:58:18 by mgarabei          #+#    #+#             */
/*   Updated: 2023/06/30 12:53:47 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_file(int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[bytes_read] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*new_line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_from_file(fd);
	new_line = ft_strchr(buffer, '\n');
	if (new_line)
	{
		*new_line = '\0';
		free(remainder);
		remainder = ft_strdup(new_line + 1);
	}
	else
	{
		free(remainder);
		remainder = NULL;
	}
	if (remainder)
		line = ft_strdup(remainder);
	else
		line = ft_strdup(buffer);
	free(buffer);
	return (line);
}
