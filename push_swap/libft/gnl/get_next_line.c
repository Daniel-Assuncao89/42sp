/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:01:17 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 18:01:18 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	fds[1024][BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (fds[fd][0] == '\0')
	{
		bytes_read = read(fd, fds[fd], BUFFER_SIZE);
		if (bytes_read <= 0)
			return (NULL);
		fds[fd][bytes_read] = '\0';
	}
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line)
		return (NULL);
	*line = '\0';
	if (search_for_break(line, fds[fd]))
		return (line);
	line = read_file(fd, line, fds[fd], (BUFFER_SIZE + 1));
	if (*line == '\0')
		return (clean(line));
	return (line);
}
