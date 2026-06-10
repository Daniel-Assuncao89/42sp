/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 14:26:09 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/10 19:03:23 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long long ptr_ul, char *hex)
{
	int		count;

	count = 0;
	if (ptr_ul >= 16)
		count += ft_puthex(ptr_ul / 16, hex);
	write(1, &hex[ptr_ul % 16], 1);
	return (count + 1);
}

int	ft_printptr(void *ptr)
{
	unsigned long long		ptr_ul;
	char					*hex;
	int						count;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count = 0;
	hex = "0123456789abcdef";
	ptr_ul = (unsigned long long)ptr;
	write(1, "0x", 2);
	count = 2;
	count += ft_puthex(ptr_ul, hex);
	return (count);
}
