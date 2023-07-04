/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 10:58:18 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/04 11:31:26 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_remainder(int fd, char *buffer, char *remainder)
{
	int		bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (bytes_read != '\0')
	//why is this condition like this?
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (0);
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

static char	*get_line(char *line)
{
	int		i;
	char	*remainder;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0')
		return (0);
	remainder = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*remainder == '\0')
	{
		free(remainder);
		remainder = NULL;
	}
	line[i + 1] = '\0';
	return (remainder);
}

char	*get_next_line(int fd)
{
	char		*current_line;
	char		*buffer;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	current_line = read_to_remainder(fd, buffer, remainder);
	free(buffer);
	buffer = NULL;
	if (!current_line)
		return (NULL);
	remainder = get_line(current_line);
	return (current_line);
}
