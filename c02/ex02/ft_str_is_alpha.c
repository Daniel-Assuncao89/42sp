/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:34:18 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/10 15:15:41 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int		ft_str_is_alpha(char *str)
{
	int i;
	int verificador;

	i = 0;
	verificador = 1;
	while(str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || ( str[i] >= 'A' && str[i] <= 'Z'))
		{
			i++;
			continue;
		}
		else if (str[i] == ' ' && i == 0)
		{
			i++;
			continue;
		}
		else
		{
			verificador = 0;
			return (verificador);
		}
		i++;
	}
	
	return (verificador);
}

int main(void)
{
	char *str;

	str = " ";
	printf("%d", ft_str_is_alpha(str));
}
