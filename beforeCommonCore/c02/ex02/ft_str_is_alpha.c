/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:34:18 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/11 14:52:21 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alpha(char str)
{
	if (str >= 'a' && str <= 'z')
	{
		return (1);
	}
	else if (str >= 'A' && str <= 'Z')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		verify;

	i = 0;
	verify = 1;
	while (str[i] != '\0')
	{
		if (ft_is_alpha(str[i]))
		{
			i++;
			continue ;
		}
		else if (str[i] == ' ' && i == 0)
		{
			i++;
			continue ;
		}
		else
		{
			verify = 0;
			return (verify);
		}
		i++;
	}	
	return (verify);
}
/*
#include <stdio.h>
int main(void)
{
	printf("Somente caracter: %d\n", ft_str_is_alpha("asdbBHKijdk"));
	printf("Caracteres diversos: %d\n", ft_str_is_alpha("asdb !BHKijdk"));
	printf("Vazia: %d\n", ft_str_is_alpha(""));
}
*/
