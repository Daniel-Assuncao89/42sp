/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 15:18:23 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/12 17:14:07 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_print_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_putstr(argv[i++]);
		ft_putchar('\n');
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
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
}
