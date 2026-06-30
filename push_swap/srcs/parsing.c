/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:26:27 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/30 19:10:27 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
static int has_flag(char *argv)
{
	if (argv[0] == '-' && argv[1] == '-')
		return (1);
	else if (argv[0] == '-' && argv[1] != '-')
		return (-1);
	return (0);
}

static void error_msg()
{
	const char	*msg;

	msg = "Error\n";
	write(1, msg, 6);
}

static int	parsing(char **argv)
{
	int	code;
	int	valid;
	int	i;

	code = 0;
	valid = 0;
	i = 1;
	code = has_flag(argv[i]);
	if (code > 0)
		i++;
	else if (code < 0)
		return (-1);
	while (argv[i])
	{
		ft_split(argv[i]);
		if ( valid < 0)
			return (-1);
		i++;
	}
}

int main(int argc, char **argv)
{
	int	validator;

	validator = 0;
	if (argc < 2)
		return (0);
	if (argc >= 4)
		validator = parsing(argv);
	if (validator < 0)
		error_msg();
	return (validator);	
}
