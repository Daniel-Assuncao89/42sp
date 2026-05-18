/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:42:07 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/14 17:16:37 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int		count_dest;
	int		count_src;

	count_dest = 0;
	count_src = 0;
	while (dest[count_dest])
		count_dest++;
	while (src[count_src])
	{
		dest[count_dest] = src[count_src];
		count_dest++;
		count_src++;
	}
	dest[count_dest] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
	char s1[50] = "Today is ";
	char s2[] = "going to be great";
	char s3[50] = "Today is ";

	printf("Expected result:%s\n\n", strcat(s1, s2));
	printf("Result:%s\n", ft_strcat(s3, s2));
}
*/
