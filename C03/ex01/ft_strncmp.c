/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:19:07 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/14 15:36:58 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	count;
	int				str_ascii_value;

	count = 0;
	while ((s1[count] && s2[count]) && count < n)
	{
		str_ascii_value = s1[count] - s2[count];
		if (s1[count] != s2[count])
			return (str_ascii_value);
		count++;
	}
	if (n == 0)
		return (0);
	else if (!s1[count] || !s2[count])
		str_ascii_value = s1[count] - s2[count];
	return (str_ascii_value);
}
/*
#include <stdio.h>
#include <string.h>
int main (void)
{
    printf("Exercice 01 : ft_strncmp \n\n");
    char str1[] = "camiri", str2[] = "";
    int nbr = 7;
    printf("Result: %d\n\n", ft_strncmp(str1, str2, nbr));
    printf("Expected outcome: %d \n", strncmp(str1, str2, nbr));
}
*/
