/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 21:07:37 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/16 22:33:54 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str);

int	main(int argc, char **argv)
{
	int	fd;
	int	bytes;
	int	buffer[1024];

	if (argc == 1)
	{
		ft_putstr("File name missing.");
		return (0);
	}
	else if (argc > 2)
	{
		ft_putstr("Too many arguments");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	bytes = read(fd, buffer, 1024);
	write(1, buffer, bytes);
	
	return (0);
}
