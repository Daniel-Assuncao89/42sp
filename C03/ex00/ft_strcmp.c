/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 14:04:09 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/14 17:54:32 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int		count;
	int		str_ascii_value;

	count = 0;
	while ((s1[count] && s2[count]) && (s1[count] == s2[count]))
	{
		count++;
	}
	str_ascii_value = s1[count] - s2[count];
	return (str_ascii_value);
}
/*
#include <stdio.h>
#include <string.h>

int main (void)
{
    printf("Exercice 00 : ft_strcmp \n\n");
    char str1[] = "cam", str2[] = "cma";
    printf("Result: %d\n\n", ft_strcmp(str1, str2));
    printf("Expected outcome: %d \n", strcmp(str1, str2));
}
*/
