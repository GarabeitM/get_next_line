/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 11:50:46 by mgarabei          #+#    #+#             */
/*   Updated: 2023/06/28 11:52:11 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*new_line;

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
		printf("%s\n", new_line);
		free(new_line);
		new_line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
