/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 12:14:04 by dassunca          #+#    #+#             */
/*   Updated: 2026/07/17 12:14:08 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_limit(long long num, int sign)
{
	if (sign == 1 && num > 2147483647)
		return (0);
	if (sign == -1 && num > 2147483648)
		return (0);
	return (1);
}

int	ft_atoi_ps(char *str, int *result)
{
	long long	num;
	int			sign;
	int			i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	while (str[i++])
	{
		if (!ft_isdigit(str[i - 1]))
			return (0);
		num = (num * 10) + (str[i - 1] - '0');
		if (!check_limit(num, sign))
			return (0);
	}
	*result = (int)(num * sign);
	return (1);
}
