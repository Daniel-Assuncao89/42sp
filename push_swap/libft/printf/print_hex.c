/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 16:10:48 by hequeiro          #+#    #+#             */
/*   Updated: 2026/06/12 16:10:49 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_to_lower(char *x)
{
	while (*x)
	{
		if (*x >= 'A' && *x <= 'Z')
			*x += 32;
		x++;
	}
}

int	to_hex(unsigned int n, char capitalize)
{
	char	result[20];
	int		i;
	int		temp;

	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	i = 0;
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			result[i++] = temp + '0';
		else
			result[i++] = temp + 'A' - 10;
		n /= 16;
	}
	result[i--] = '\0';
	if (capitalize == 'x')
		str_to_lower(result);
	while (i >= 0)
		ft_putchar_fd(result[i--], 1);
	return (ft_strlen(result));
}

int	to_hex_pointer(void *nb)
{
	unsigned long long	n;
	char				result[30];
	int					i;
	int					temp;

	n = (unsigned long long)nb;
	i = 0;
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			result[i++] = temp + '0';
		else
			result[i++] = temp + 'a' - 10;
		n /= 16;
	}
	result[i++] = 'x';
	result[i++] = '0';
	result[i--] = '\0';
	while (i >= 0)
		ft_putchar_fd(result[i--], 1);
	return (ft_strlen(result));
}

void	handle_p(va_list arg_list, int *counter)
{
	void	*temp;

	temp = va_arg(arg_list, void *);
	if (!temp)
	{
		ft_putstr_fd("(nil)", 1);
		*counter += 5;
	}
	else
		*counter += to_hex_pointer(temp);
}
