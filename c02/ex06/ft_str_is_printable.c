/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:21:02 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/12 16:10:49 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("Printable caracters: %d\n", ft_str_is_printable("$%@[]{}asc/;~"));
	printf("Non printable caracters: %d\n", ft_str_is_printable("			"));
	printf("Empty string: %d\n", ft_str_is_printable(""));
}
*/
