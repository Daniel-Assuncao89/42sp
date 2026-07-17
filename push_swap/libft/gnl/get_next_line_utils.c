/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 18:00:01 by hequeiro          #+#    #+#             */
/*   Updated: 2026/07/15 18:00:03 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	search_for_break(char *line, char *buffer)
{
	char	*buf_init;
	int		found;
	char	break_char;

	break_char = '\n';
	buf_init = buffer;
	found = 0;
	while (*line)
		line++;
	while (*buffer != '\0' && *buffer != break_char)
		*(line++) = *(buffer++);
	if (*buffer == break_char)
	{
		*(line++) = *(buffer++);
		found = 1;
	}
	*line = '\0';
	while (*buffer)
		*(buf_init++) = *(buffer++);
	*buf_init = '\0';
	return (found);
}

void	my_strcpy(char *dest, char *src)
{
	while (*src)
		*(dest++) = *(src++);
	*dest = '\0';
}

static char	*my_realloc(char *line, int total_bytes)
{
	char	*new_line;

	new_line = malloc(sizeof(char) * total_bytes);
	if (!new_line)
	{
		free (line);
		return (NULL);
	}
	my_strcpy(new_line, line);
	free(line);
	return (new_line);
}

char	*read_file(int fd, char *line, char *buffer, int total_bytes)
{
	int	bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		total_bytes += bytes_read;
		buffer[bytes_read] = '\0';
		line = my_realloc(line, total_bytes);
		if (!line)
			return (NULL);
		if (search_for_break(line, buffer))
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (line);
}

char	*clean(char *line)
{
	free(line);
	return (NULL);
}
