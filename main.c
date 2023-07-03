/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:43:09 by mgarabei          #+#    #+#             */
/*   Updated: 2023/06/29 16:22:57 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		i;
	char	*new_line;

	i = 1;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		close(fd);
		return (-1);
	}
	new_line = get_next_line(fd);
	while (new_line != NULL)
	{
		printf("line %d: %s\n", i, new_line);
		new_line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}

/*
int	main(void)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		printf("%s\n", line);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (0);
}*/
