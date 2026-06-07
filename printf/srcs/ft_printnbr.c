/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 15:52:44 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/07 16:01:30 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnbr(int nbr)
{
	long	nbr_l;
	int		count;
	char	c;

	nbr_l = nbr;
	count = 0;
	if (nbr_l < 0)
	{
		write(1, "-", 1);
		nbr_l *= -1;
		count++;
	}
	if (nbr_l >= 10)
		count += ft_printnbr((int)nbr_l / 10);
	c = (nbr_l % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}
