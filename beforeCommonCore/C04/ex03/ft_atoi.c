/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/18 14:11:51 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/18 19:33:15 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	return(i);
}

char	ft_sign(char *str)
{
	int	i;
	int minus;

	i = 0;
	minus = 0;
	while(str[i] != '\0')
	{
		if (str[i] == '-')
			minus += 1;
		i++;
	}
	if (minus % 2 == 1)
		return ('-');
	return ('+');
}

#include <stdio.h>
int		ft_atoi(char *str)
{
	int		i;
	int		number;
	char	sign;

	number = 0;
	i = ft_isspace(str);
	sign = ft_sign(str);
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			number = (number * 10) + (str[i] - '0');
		i++;
	}
	if (sign == '-')
		number *= -1;
	return (number);
}

int		main(void)
{
	char	*str;

	str = "    +--+-427a6";
	printf("%d\n", ft_atoi(str));
	return (0);
}
