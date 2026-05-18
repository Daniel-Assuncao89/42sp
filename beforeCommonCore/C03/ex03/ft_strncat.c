/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:19:30 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/14 17:33:27 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int					count_dest;
	unsigned int		count_src;

	count_dest = 0;
	count_src = 0;
	if (nb == 0)
		return (dest);
	while (dest[count_dest])
		count_dest++;
	while (src[count_src] && count_src < nb)
	{
		dest[count_dest] = src[count_src];
		count_src++;
		count_dest++;
	}
	dest[count_dest] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char s1[50] = "abc";
	char s2[] = "def";
	char s3[50] = "abc";
	printf("Expected result:%s\n\n", strncat(s1, s2, 2));
	printf("Result:%s\n", ft_strncat(s3, s2, 2));
}
*/
