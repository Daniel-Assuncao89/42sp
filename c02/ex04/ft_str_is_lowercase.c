/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dassunca <dassunca.student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 15:36:02 by dassunca          #+#    #+#             */
/*   Updated: 2026/04/11 15:52:49 by dassunca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			i++;
			continue ;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}
/*
#include <stdio.h>
int main(void)
{
	printf("Only lowercase: %d\n", ft_str_is_lowercase("abcvsgsjha"));
	printf("Lowercase and Uppercase: %d\n", ft_str_is_lowercase("abcOsgHjha"));
	printf("Empty string: %d\n", ft_str_is_lowercase(""));
}
*/
