/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 13:48:54 by dassunca          #+#    #+#             */
/*   Updated: 2026/07/20 13:50:17 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_new_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*extracted_line(char *buffer)
{
	int		i;
	int		len;
	char	*line;

	i = 0;
	i = has_new_line(buffer);
	if (i != -1)
		len = i + 1;
	else
		len = ft_strlen(buffer);
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	ft_strlcpy(line, buffer, (len + 1));
	return (line);
}

static char	*stash_readstr(char *buffer, int fd)
{
	char	*stashed;
	int		rd_bytes;

	stashed = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stashed)
		return (NULL);
	stashed[0] = '\0';
	rd_bytes = 1;
	while (has_new_line(stashed) == -1 && rd_bytes != 0)
	{
		rd_bytes = read(fd, stashed, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(stashed);
			free(buffer);
			return (NULL);
		}
		stashed[rd_bytes] = '\0';
		buffer = ft_strjoin(buffer, stashed);
	}
	free(stashed);
	return (buffer);
}

static char	*new_stash_readstr(char *buffer)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i] || buffer[i + 1] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new_str = malloc((ft_strlen(buffer) - i) * sizeof(char));
	if (!new_str)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		new_str[j++] = buffer[i++];
	new_str[j] = '\0';
	free(buffer);
	return (new_str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stashed;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stashed = stash_readstr(stashed, fd);
	if (!stashed)
		return (NULL);
	line = extracted_line(stashed);
	stashed = new_stash_readstr(stashed);
	if (line && line[0] == '\0')
	{
		free(line);
		line = NULL;
		if (stashed)
		{	
			free(stashed);
			stashed = NULL;
		}
	}
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>
int main(int argc, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (argc);
}
*/