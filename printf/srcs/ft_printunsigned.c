/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:26:38 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/07 16:28:39 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printunsigned(unsigned int nbr)
{
	int		count;
	char	c;

	count = 0;
	if (nbr >= 10)
		count += ft_printunsigned(nbr / 10);
	c = (nbr % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}
