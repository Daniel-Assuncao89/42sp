/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:45:44 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/21 12:40:06 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_params(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write (1, str, i);
	write (1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i >= 1)
	{
		ft_rev_params(argv[i]);
		i--;
	}
	return (argc);
}
