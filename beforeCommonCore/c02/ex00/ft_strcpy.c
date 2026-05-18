/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 16:41:24 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/08 12:39:43 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
/*
#include <unistd.h>
int		main(void)
{
	char *src;
	char dest[100];
	char *result;
	int count;

	count = 0;
	src = "Hello, buddy";
	result = ft_strcpy(dest, src);
	while (result[count] != '\0')
    {
		 count++;
    }
	write(1, result, count);
	return (0);
}
*/
