/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:48:54 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/11 19:38:27 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes;
	char		*buffer;
	static char	*line;

	line = NULL;
	bytes = 0;
	buffer = (char *) malloc (BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer || fd < 0)
		return (NULL);
	if (!line)
		bytes = read(fd, buffer, BUFFER_SIZE);
	write(1, buffer, bytes);
	free(buffer);
	return (buffer);
}
#include <fcntl.h>
int main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
}
