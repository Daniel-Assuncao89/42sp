/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 16:03:32 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/21 12:36:17 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_print_arg(int argc, char **argv)
{
	int	params;

	params = 1;
	while (params < argc)
	{
		write (1, argv[params], ft_strlen(argv[params]));
		write (1, "\n", 1);
		params++;
	}
}

int	main(int argc, char **argv)
{
	int		params;
	int		params2;
	char	*comp;

	params = 1;
	while (params < argc)
	{
		comp = argv[params];
		params2 = params + 1;
		while (params2 < argc)
		{
			if (ft_strcmp(argv[params], argv[params2]) > 0)
			{
				argv[params] = argv[params2];
				argv[params2] = comp;
				comp = argv[params];
			}
			params2++;
		}
		params++;
	}
	ft_print_arg(argc, argv);
	return (argc);
}
