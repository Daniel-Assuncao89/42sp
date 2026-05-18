/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 14:54:54 by dassunca          #+#    #+#             */
/*   Updated: 2026/05/12 17:13:55 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

int	main(int argc, char **argv)
{
	int	params;

	params = 1;
	while (params < argc)
	{
		ft_putstr(argv[params++]);
		ft_putchar('\n');
	}
}
