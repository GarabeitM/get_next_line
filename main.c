/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:43:09 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/19 16:23:05 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read from a file
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	fd = open("tests/file.txt", O_RDONLY);
	line = ft_strdup("");
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("line %i: %s\n", i, line);
		free(line);
		i++;
	}
	if (close(fd) == -1)
	{
		printf("Failed to close the file\n");
		return (1);
	}
	return (0);
}

//read from stdin
int main(void)
{
    char *line;

    printf("Please enter a line or type \"quit\" to quit:\n");
    line = get_next_line(0);
    while (line != NULL)
    {
        if (strncmp(line, "quit", 4) == 0)
        {
            printf("Bye!\n");
			break ;
        }
		printf("You have entered: %s\n", line);
		printf("What else?\n");
        free(line);
        line = get_next_line(0);
    }
	free(line);
    return (0);
}
