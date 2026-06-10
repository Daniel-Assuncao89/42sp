/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:52:58 by dassunca          #+#    #+#             */
/*   Updated: 2026/06/10 17:17:20 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(const char *src)
{
	size_t	len;

	len = 0;
	if (!src)
		return (len);
	len = ft_strlen(src);
	write(1, src, len);
	return ((int)len);
}
