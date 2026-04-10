/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:34:18 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/10 16:31:59 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;
	int		verify;

	i = 0;
	verify = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
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
	char *str;

	str = "abnmsahdjk";
	printf("%d", ft_str_is_alpha(str));
}
*/
