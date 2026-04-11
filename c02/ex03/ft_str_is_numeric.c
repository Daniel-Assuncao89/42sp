/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.sp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 14:24:30 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/11 15:52:06 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			continue ;
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
	printf("Vazia: %d\n", ft_str_is_numeric(""));
	printf("Somente numeros: %d\n", ft_str_is_numeric("1234567890"));
	printf("Com caracteres alem de numero: %d\n", ft_str_is_numeric("123e@67"));
}
*/
