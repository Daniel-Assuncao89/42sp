/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 16:08:10 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/07 17:22:21 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhex(int c, unsigned int nbr)
{
	const char	*hex;
	int			count;

	count = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_printhex(c, nbr / 16);
	write(1, &hex[nbr % 16], 1);
	return (count + 1);
}
