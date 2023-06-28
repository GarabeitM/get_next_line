/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:48:16 by mgarabei          #+#    #+#             */
/*   Updated: 2023/06/28 11:52:02 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_line(int fd, char *remainder, char **line)
{
	int		bytes_read;
	char	*temp;
	char	*newline;

	newline = ft_strchr(remainder, '\n');
	while (!newline)
	{
		bytes_read = read(fd, remainder, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (bytes_read);
		remainder[bytes_read] = '\0';
		newline = ft_strchr(remainder, '\n');
		temp = *line;
		*line = ft_strjoin(*line, remainder);
		free(temp);
		if (!*line)
			return (-1);
	}
	*newline = '\0';
	newline++;
	ft_strlcpy(remainder, newline, BUFFER_SIZE);
	return (1);
}

char	*get_next_line(int fd)
{
	static char		*remainder;
	char			*line;
	int				result;

	remainder = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	line = NULL;
	if (fd < 0)
		return (NULL);
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = '\0';
	result = read_line(fd, remainder, &line);
	if (result == -1 || (result == 0 && line[0] == '\0'))
	{
		free(line);
		return (NULL);
	}
	return (line);
}
