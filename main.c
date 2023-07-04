/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:43:09 by mgarabei          #+#    #+#             */
/*   Updated: 2023/07/04 13:59:38 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
//check line 32
int	main(void)
{
	int		i;
	int		fd;
	char	*line;

	i = 1;
	fd = open("tests/read_error.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed to open the file\n");
		return (1);
	}
	line = get_next_line(fd);
	printf("line %i: %s\n", i, line);
	free(line);
	i++;
	while ((line = get_next_line(fd)) != NULL)
	{
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


int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;
	
	fd1 = open("file.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}*/
