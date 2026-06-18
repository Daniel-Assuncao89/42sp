/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:52:58 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/12 12:01:00 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(const char *src)
{
	int	len;

	len = 0;
	if (!src)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(src);
	write(1, src, len);
	return (len);
}
