/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 11:53:38 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/18 14:15:04 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		bytes;
	char	buffer[1024];

	if (argc != 2)
	{
		if (argc < 2)
			ft_putstr("File name missing.\n");
		else if (argc > 2)
			ft_putstr("Too many arguments.\n");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	bytes = read(fd, buffer, 1024);
	while (bytes > 0)
	{
		write(1, buffer, bytes);
		bytes = read(fd, buffer, 1024);
	}
	close(fd);
	return (0);
}
