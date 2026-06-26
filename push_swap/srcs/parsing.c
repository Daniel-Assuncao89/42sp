/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 12:26:27 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/25 20:05:25 by dassunca         ###   ########.fr       */
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

int	is_digit(int c)
{
	return ((c > '0' && c < '9'));
}

int argv_validator(char *str)
{
	int idx;
	int	number_qty;

	idx = 0;
	number_qty = 0;
	/*while (str[idx] == 32)
		idx++;*/
	while (str[idx])
	{
		/*if (!is_digit(str[idx]) && str[idx] != 32)
			return (0);
		*/
		while (is_digit(str[idx]))
		{
			if (str[idx + 1] == '\0' || str[idx + 1] == 32)
				number_qty++;
			idx++;
		}
		idx++;
	}
	return (number_qty);
}

int	*argv_split(char *str)
{
	int	*a_stack;
	int	idx;
	int	idx_cp;

	idx = 0;
	idx_cp = 0;
	a_stack = malloc (argv_validator(str) * sizeof(int));
	while (str[idx] && (is_digit(str[idx] || str[idx] == 32)))
	{
		if (is_digit(str[idx]) && idx == 0))
			a_stack[idx_cp] = str[idx];
		else if (is_digit(str[idx]))
		else if (str[idx] == 32)
		idx++;
	}
}

int main(int argc, char **argv)
{
	int	code;

	if (argc < 2)
		return (0);
	code = 0;
	code = has_flag(argv[1]);
	printf("%d", argc);
	if (code > 0 && argc == 4)
	{
		if(argv_validator(argv[1]))
			argv_split(argv[1]));
		else
			error_msg();
	}
	else if (code < 0)
		error_msg();
	else
	{
		
	}
	return (0);	
}
