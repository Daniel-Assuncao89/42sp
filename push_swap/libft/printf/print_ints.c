/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hequeiro <hequeiro@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 16:06:27 by hequeiro          #+#    #+#             */
/*   Updated: 2026/06/12 16:06:31 by hequeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_numlen(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	handle_d(va_list arg_list, int *counter)
{
	int	nb;

	nb = va_arg(arg_list, int);
	ft_putnbr_fd(nb, 1);
	*counter += ft_numlen(nb);
}

static void	ft_putlong(long n)
{
	char	x;

	if (n > 9)
		ft_putlong(n / 10);
	x = (n % 10) + '0';
	write(1, &x, 1);
}

void	handle_u(va_list arg_list, int *counter)
{
	unsigned int	nb;

	nb = va_arg(arg_list, unsigned int);
	ft_putlong(nb);
	*counter += ft_numlen(nb);
}
